<?php
/**
 * @file
 * Administrative form functions for the University of Iowa branding bar.
 */

/**
 * Page callback: University of Iowa branding bar configuration form.
 *
 * @see uiowa_bar_menu()
 */
function uiowa_bar_config_form($form, &$form_state) {
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>These settings allows you to customize the top University of Iowa branding bar.</p>'),
  );

  $form['uiowa_bar_wordmark'] = array(
    '#type' => 'radios',
    '#title' => t('Wordmark'),
    '#default_value' => variable_get('uiowa_bar_wordmark'),
    '#options' => array(
      'uiowa' => t('University'),
      'uihc' => t('UI Healthcare')
    ),
    '#description' => t('Choose between the University or UI Healthcare wordmarks'),
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
