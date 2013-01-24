<?php

/**
 * @file
 *
 * Build and theme the University of Iowa branding bar
 */

/**
 * Build out the University of Iowa branding bar.
 */
function build_uiowa_bar() {
  $uiowa_bar = array();
  $uiowa_bar['ui-global-bar'] = array(
    '#attributes' => array('id' => array('ui-global-bar')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['ui-logo'] = array(
    '#attributes' => array('id' => array('ui-logo')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['ui-logo']['link'] = array(
    '#type' => 'link',
    '#title' => t('The University of Iowa'),
    '#href' => 'http://www.uiowa.edu',
  );
  $uiowa_bar['ui-global-bar']['ui-global-bar-nav'] = array(
    '#attributes' => array('id' => array('ui-global-bar-nav')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['ui-global-bar-nav']['ui-global-links'] = array(
    '#attributes' => array('id' => array('ui-global-links')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['ui-global-bar-nav']['ui-global-links']['links'] = array(
    '#theme' => 'uiowa_bar_link_list',
    '#children' => array(
      0 => array(
        'label' => t('Phonebook'),
        'url' => 'http://www.uiowa.edu/homepage/directories/',
        'class' => 'phonebook',
        'title' => 'University of Iowa Phonebook'
      ),
      1 => array(
        'label' => t('Maps'),
        'url' => 'http://www.uiowa.edu/homepage/hub/tours.html',
        'class' => 'maps',
        'title' => 'University of Iowa Maps'
      ),
      2 => array(
        'label' => t('A-Z Index'),
        'url' => 'http://www.uiowa.edu/homepage/search/index.html',
        'class' => 'a-z',
        'title' => 'University of Iowa A-Z Index'
      ),
      3 => array(
        'label' => t('Search'),
        'url' => '#',
        'class' => 'search',
        'title' => 'University of Iowa Search'
      )
    )
  );
  $uiowa_bar['ui-global-bar']['ui-global-bar-nav']['gsa-search'] = array(
    '#attributes' => array('id' => array('gsa-search')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['ui-global-bar-nav']['gsa-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');
  return $uiowa_bar;
}

/**
 * Build out search form for the GSA.
 */
function uiowa_bar_search_form($form, &$form_state) {
  $form = array();
  $form['fieldset'] = array (
    '#type' => 'fieldset'
  );
  $form['fieldset']['search-terms'] = array (
    '#prefix' => '<legend class="element-hidden">Search</legend><div id="search-box">',
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => 'Search uiowa.edu'
    ),
    '#maxlength' => '256',
    '#size' => '15'
  );
  $form['fieldset']['submit-search'] = array (
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
    '#suffix' => '</div>'
  );
  $form_state['action'] = 'gsearch/';

  // use core search CSS in addition to this module's css
  // (keep it general in case core search is enabled)
  $form['#attributes']['class'][] = 'search-form';
  $form['#attributes']['class'][] = 'search-google-appliance-search-form';

  return $form;
}

/**
 * Submit handler for full search form
 */
function uiowa_bar_search_form_submit($form, &$form_state) {

  // set the redirect
  $search_query = urlencode($form_state['input']['search-terms']);
  $form_state['redirect'] = url($form_state['action'] . $search_query, array('absolute' => TRUE));
}

/**
 * Base URL without the protocol - needed for the Google Search Appliance.
 */
function uiowa_bar_base_url_no_protocol() {
  $url = preg_replace('/^https?:\/\//i', '', $GLOBALS['base_url']);
  return $url;
}

/**
 * Theme function to build a list of action links for the University of Iowa
 * branding bar.
 */
function theme_uiowa_bar_link_list($variables = array()) {
  $type = variable_get('uiowa_bar_link_style');
  $links = array();
  foreach ($variables['links']['#children'] as $link) {
    if ($type === 'uiowa-text') {
      $prefix = '<strong>';
    }
    else {
      $prefix = '<span aria-hidden="true" class="icon-' . $link['class'] . '"></span><strong>';
    }
    $link_content = array(
      '#prefix' => $prefix,
      '#type' => 'markup',
      '#markup' => $link['label'],
      '#suffix' => '</strong>',
    );
    $link_url = $link['url'];
    $links[] = l(render($link_content), $link_url, array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array($type, $link['class']),
        'title' => $link['title'])
      )
    );
  }
  return theme('item_list', array('items' => $links));
}
