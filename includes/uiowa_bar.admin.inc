<?php

/**
 * @file
 *
 * Administrative form functions for the University of Iowa branding bar
 */

/**
* Page callback: University of Iowa branding bar
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
      'skin-a' => t('Light Theme'),
      'skin-b' => t('Dark Theme'),
    ),
  );

  $form['uiowa_bar_link_style'] = array(
    '#type' => 'select',
    '#title' => t('Link Style'),
    '#default_value' => variable_get('uiowa_bar_link_style'),
    '#description' => t('Choose the link style for the University of Iowa branding bar action links'),
    '#options' => array(
      'uiowa-icon' => t('Icon-based'),
      'uiowa-text' => t('Text-based'),
    ),
  );

  $form['uiowa_bar_search_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close search form on wide screen displays.'),
    '#default_value' => variable_get('uiowa_bar_search_display'),
    '#description' => t('Display option for the search form to on wide displays. Defaults to closed.  On small screen displays, the search will always default to closed.'),
  );


  return system_settings_form($form);
}
