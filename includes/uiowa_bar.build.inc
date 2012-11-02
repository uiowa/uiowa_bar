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
        'title' => 'Phonebook'
      ),
      1 => array(
        'label' => t('Maps'),
        'url' => 'http://www.uiowa.edu/homepage/hub/tours.html',
        'class' => 'maps',
        'title' => 'Maps'
      ),
      2 => array(
        'label' => t('A-Z'),
        'url' => 'http://www.uiowa.edu/homepage/search/index.html',
        'class' => 'a-z',
        'title' => 'A-Z'
      ),
      3 => array(
        'label' => t('Search'),
        'url' => '#',
        'class' => 'search',
        'title' => 'Search'
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
  $form['#action'] = 'http://search.uiowa.edu/search';
  $form['#method'] = 'get';
  $form['fieldset'] = array (
    '#type' => 'fieldset'
  );
  $form['fieldset']['search-terms'] = array (
    '#prefix' => '<legend class="element-hidden">Search</legend><div id="search-box">',
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => 'Start Searching ...'
    ),
    '#name' => 'q',
    '#maxlength' => '256',
    '#size' => '15'
  );
  $form['fieldset']['sitesearch'] = array (
    '#prefix' => '<div id="sitesearch-container">',
    '#type' => 'select',
    '#title' => t('for'),
    '#name' => 'sitesearch',
    '#options' => array(
      uiowa_bar_base_url_no_protocol() => 'This Site',
      'www.uiowa.edu' => 'All Sites'
    )
  );
  $form['fieldset']['submit-search'] = array (
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
    '#suffix' => '</div>'
  );
  $form['fieldset']['hidden-site'] = array (
    '#type' => 'hidden',
    '#value' => t('default_collection'),
    '#name' => 'site',
  );
  $form['fieldset']['hidden-client'] = array (
    '#type' => 'hidden',
    '#value' => t('default_frontend'),
    '#name' => 'client',
  );
  $form['fieldset']['hidden-output'] = array (
    '#type' => 'hidden',
    '#value' => t('xml_no_dtd'),
    '#name' => 'output',
  );
  $form['fieldset']['hidden-proxystylesheet'] = array (
    '#type' => 'hidden',
    '#value' => t('default_frontend'),
    '#name' => 'proxystylesheet',
    '#suffix' => '</div>'
  );
  return $form;
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
