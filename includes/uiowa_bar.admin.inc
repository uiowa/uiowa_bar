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
    '#description' => t('Choose the color palette of the University of Iowa Branding Bar'),
    '#options' => array(
      'uiowa-bar-light' => t('Light Theme'),
      'uiowa-bar-gold' => t('Gold Theme'),
      'uiowa-bar-dark' => t('Dark Theme'),
      'uiowa-bar-large-dark' => t('Large Dark Theme'),
    ),
  );

  $form['uiowa_bar_varient'] = array(
    '#type' => 'select',
    '#title' => t('Varient'),
    '#default_value' => variable_get('uiowa_bar_varient'),
    '#description' => t('Choose the varient of the University of Iowa Branding Bar'),
    '#options' => array(
      'standard-varient' => t('Standard'),
      'osl-varient' => t('Division of Student Life'),
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

  $form['uiowa_bar_cse_engine_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Engine ID'),
    '#default_value' => variable_get('uiowa_bar_cse_engine_id'),
    '#description' => t('Enter the CSE Engine ID. The default is 015014862498168032802:ben09oibdpm.'),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['uiowa_bar_cse_scope'] = array(
    '#type' => 'checkbox',
    '#title' => t('Limit Custom Search to this Site'),
    '#default_value' => variable_get('uiowa_bar_cse_scope'),
    '#description' => t('If checked, the Google Custom Search will be scoped to this site only. If you are using a CSE ID that includes multiple sites in it, you will likely want to uncheck this.'),
    '#size' => 60,
  );

  return system_settings_form($form);
}
