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

  return system_settings_form($form);
}
