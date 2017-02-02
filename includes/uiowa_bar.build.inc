<?php
/**
 * @file
 * Build and theme the University of Iowa branding bar.
 */

/**
 * Build out the University of Iowa branding bar.
 */
function build_uiowa_bar() {
  $path = drupal_get_path('module', 'uiowa_bar');
  $wordmark = variable_get('uiowa_bar_wordmark');
  $uiowa_bar = array();

  $uiowa_bar['uiowa-bar'] = array(
    '#attributes' => array('id' => array('uiowa-bar')),
    '#type' => 'container',
  );

  $uiowa_bar['uiowa-bar']['container'] = array(
    '#attributes' => array('class' => array('wrapper')),
    '#type' => 'container',
  );


  $uiowa_bar['uiowa-bar']['container']['wordmark'] = array(
    '#markup' => '<a href="http://www.uiowa.edu" title="The University of Iowa" id="wordmark-link" ><img src="'.$path.'/assets/'.$wordmark.'.svg"  id="wordmark"/></a>',
  );


  $uiowa_bar['uiowa-bar']['container']['uiowa-search'] = array(
    '#attributes' => array(
      'id' => array('uiowa-search'),
    ),
    '#type' => 'container',
  );

  $uiowa_bar['uiowa-bar']['container']['uiowa-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');

  // Allow other modules to alter the top render array.
  drupal_alter('uiowa_bar_top', $uiowa_bar);

  return $uiowa_bar;
}

/**
 * Build out search form for the GSA.
 */
function uiowa_bar_search_form($form, &$form_state) {
  $form = array();
  $form['search-terms'] = array(
    '#type' => 'textfield',
    '#title' => t('Search'),
    '#attributes' => array(
      'placeholder' => 'Search this site',
    ),
    '#maxlength' => '256',
    '#size' => '15',
  );
  $form['submit-search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
  );
  $form['#action'] = $GLOBALS['base_url'] . '/google-search';

  // Use core search CSS in addition to this module's css.
  // (keep it general in case core search is enabled).
  $form['#attributes']['class'][] = 'search-form';
  $form['#attributes']['class'][] = 'search-google-appliance-search-form';

  return $form;
}

/**
 * Submit handler for full search form.
 */
function uiowa_bar_search_form_submit($form, &$form_state) {
  // Set the redirect.
  $search_query = urlencode($form_state['values']['search-terms']);
  $form_state['redirect'] = url($form['#action'] . '?search=' . $search_query, array('absolute' => FALSE));
}
