<?php

/**
 * @file
 *
 * Administrative form functions for the University of Iowa branding bar
 */

/**
* Page callback: University of Iowa branding bar configuration form
*
* @see uiowa_bar_menu()
*/
function uiowa_bar_config_form($form, &$form_state) {
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>These settings allows you to customize the top University of Iowa branding bar.</p>'),
  );

  $form['uiowa_bar_color_palette'] = array(
    '#type' => 'select',
    '#title' => t('Color Palette'),
    '#default_value' => variable_get('uiowa_bar_color_palette'),
    '#description' => t('Choose the color palette of the University of Iowa branding bar'),
    '#options' => array(
      'uiowa-bar-light' => t('Light Theme'),
      'uiowa-bar-gold' => t('Gold Theme'),
      'uiowa-bar-dark' => t('Dark Theme'),
      'uiowa-bar-large-dark' => t('Large Dark Theme'),
    ),
  );

  $form['uiowa_bar_footer_location'] = array(
    '#type' => 'select',
    '#title' => t('Footer Location'),
    '#default_value' => variable_get('uiowa_bar_footer_location'),
    '#description' => t('Choose which region to render the footer. This may style the footer differently depending upon your theme.'),
    '#options' => array(
      'footer' => t('Footer Region'),
      'page_bottom' => t('Page Bottom Region'),
    ),
  );

  $form['uiowa_bar_search_tool'] = array(
    '#type' => 'select',
    '#title' => t('Search Tool'),
    '#default_value' => variable_get('uiowa_bar_search_tool'),
    '#description' => t('Choose whether you would like to use the Google Search Appliance or the Google Custom Search.'),
    '#options' => array(
      'gsa' => t('Google Search Appliance'),
      'cse' => t('Google Custom Search'),
    ),
  );

  $form['uiowa_bar_cse_engine_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Engine ID'),
    '#default_value' => variable_get('uiowa_bar_cse_engine_id'),
    '#description' => t('Enter the CSE Engine ID'),
    '#size' => 60,
    '#states' => array(
      // Show this field only when the search tool is set to cse.
      'visible' => array(
        ':input[name="uiowa_bar_search_tool"]' => array('value' => 'cse'),
      ),
      // Set field to be required when search tool is set to cse.
      // This doesn't actually work, it only displays the asterisk.
      // Will still need to add a custom validate function to actually make it required.
      'required' => array(
       ':input[name="uiowa_bar_search_tool"]' => array('value' => 'cse'),
    ),
    ),
  );

  $form['uiowa_bar_cse_scope'] = array(
    '#type' => 'checkbox',
    '#title' => t('Limit Custom Search to this Site'),
    '#default_value' => variable_get('uiowa_bar_cse_scope'),
    '#description' => t('If checked, the Google Custom Search will be scoped to this site only. If you are using a CSE ID that includes multiple sites in it, you will likely want to uncheck this.'),
    '#size' => 60,
    '#states' => array(
      // Show this field only when the search tool is set to cse.
      'visible' => array(
        ':input[name="uiowa_bar_search_tool"]' => array('value' => 'cse'),
      ),
    ),
  );

  // Adding an additional validate function to require Search Engine ID when
  // search tool is set to cse.
  $form['#validate'][] = '_uiowa_bar_config_form_validate';

  return system_settings_form($form);
}

/**
* Custom validate function.
*/
function _uiowa_bar_config_form_validate($form, &$form_state) {
  // If search tool is set to cse and cse engine id field is null then set error.
  if (($form_state['values']['uiowa_bar_search_tool'] == 'cse')
    && $form_state['values']['uiowa_bar_cse_engine_id'] == NULL){
    form_set_error('uiowa_bar_cse_engine_id', $form['uiowa_bar_cse_engine_id']['#title'] . ' field is required when ' . $form['uiowa_bar_search_tool']['#title'] . ' field is set to Google Custom Search');
  }
}
