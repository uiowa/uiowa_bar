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
    '#attributes' => array('id' => array('ui-wrapper')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container'] = array(
    '#attributes' => array('class' => array('container')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-logo'] = array(
    '#attributes' => array('id' => array('ui-logo')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-logo']['link'] = array(
    '#type' => 'link',
    '#title' => t('The University of Iowa'),
    '#href' => 'http://www.uiowa.edu',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-global-bar-nav'] = array(
    '#attributes' => array('id' => array('ui-global-bar-nav')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-global-bar-nav']['ui-global-links'] = array(
    '#attributes' => array('id' => array('ui-global-links')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-global-bar-nav']['gsa-search'] = array(
    '#attributes' => array('id' => array('gsa-search')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-global-bar-nav']['gsa-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');
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
