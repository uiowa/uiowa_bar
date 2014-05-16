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
    '#attributes' => array('class' => array('container', 'l-container')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-logo'] = array(
    '#attributes' => array('id' => array('ui-logo')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-logo']['link'] = array(
    '#markup' => '<a href="http://www.uiowa.edu" title="The University of Iowa"><i class="ui-glyph-icon-domewordsingle" aria-hidden="true"></i><span class="element-invisible">The University of Iowa</span></a>',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-search-toggle'] = array(
    '#markup' => '<a href="#" title="Open search bar" id="ui-search-toggle" class="is-active"><i class="ui-glyph-icon-ui-search" aria-hidden="true"></i><span class="element-invisible">Toggle Search</span></a>',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-search'] = array(
    '#attributes' => array(
      'id' => array('ui-search'),
      'class' => array('is-visible'),
    ),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-bar']['container']['ui-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');

  // Allow other modules to alter the top render array.
  drupal_alter('uiowa_bar_top', $uiowa_bar);

  return $uiowa_bar;
}

/**
 * Build out search form for the GSA.
 */
function uiowa_bar_search_form($form, &$form_state) {
  $form = array();
  $form['search-icon'] = array (
    '#markup' => '<i class="ui-glyph-icon-ui-search" aria-hidden="true"></i>',
  );
  $form['search-terms'] = array (
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
    '#attributes' => array(
      'placeholder' => 'Search this site',
    ),
    '#maxlength' => '256',
    '#size' => '15'
  );
  $form['submit-search'] = array (
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
  );

  if(variable_get('uiowa_bar_search_tool') == 'gsa'){
    $form['#action'] = $GLOBALS['base_path'].'gsearch/this-site/';
  }
  else{
    $form['#action'] = $GLOBALS['base_path'].'/google-search';
  }


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
  if(variable_get('uiowa_bar_search_tool') == 'gsa'){
    $form_state['redirect'] = url($form['#action'] . $search_query, array('absolute' => TRUE));
  }
  else{
    $form_state['redirect'] = url($form['#action'], array('absolute' => TRUE,'query' => array('search' => $search_query)));
  }

}
