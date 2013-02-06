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
  $uiowa_bar['ui-global-bar']['container']['ui-search-toggle'] = array(
    '#type' => 'link',
    '#title' => t('Search'),
    '#href' => '#',
    '#attributes' => array('id' => array('ui-search-toggle')),
  );
  $uiowa_bar['ui-global-bar']['container']['ui-search'] = array(
    '#attributes' => array('id' => array('ui-search')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');
  return $uiowa_bar;
}

/**
 * Build out search form for the GSA.
 */
function uiowa_bar_search_form($form, &$form_state) {
  $form = array();
  $form['search-terms'] = array (
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => 'Search uiowa.edu'
    ),
    '#maxlength' => '256',
    '#size' => '15'
  );
  $form['submit-search'] = array (
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
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
