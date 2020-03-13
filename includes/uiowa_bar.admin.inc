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
  $form['alert'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site-Wide Alert Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['alert']['uiowa_bar_alert_toggle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable alert'),
    '#description' => t('Check to display alert text site-wide.'),
    '#default_value' => variable_get('uiowa_bar_alert_toggle'),
  );
  $form['alert']['uiowa_bar_alert_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="uiowa_bar_alert_toggle"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['alert']['uiowa_bar_alert_container']['uiowa_bar_alert_severity'] = array(
    '#type' => 'select',
    '#title' => t('Alert Severity'),
    '#default_value' => variable_get('uiowa_bar_alert_severity'),
    '#options' => array(
      'low' => t('Low'),
      'medium' => t('Medium'),
      'high' => t('High')
    ),
  );
//  $form['alert']['uiowa_bar_alert_container']['uiowa_bar_alert_title'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Alert Title'),
//    '#default_value' => variable_get('uiowa_bar_alert_title'),
//    '#size' => 60,
//  );
  $defaults = array('value' => '', 'format' => 'filtered_html');
  $uiowa_bar_alert = variable_get('uiowa_bar_alert');
  empty($uiowa_bar_alert) ? $uiowa_bar_alert = $defaults : $uiowa_bar_alert;
  $form['alert']['uiowa_bar_alert_container']['uiowa_bar_alert'] = array(
    '#type' => 'text_format',
    '#title' => t('Alert Text'),
    '#default_value' => $uiowa_bar_alert['value'],
    '#description' => t('Enter the alert information to display site-wide.'),
    '#format' => $uiowa_bar_alert['format'],
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

  $form['uiowa_bar_link1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['uiowa_bar_link1']['uiowa_bar_link1_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('uiowa_bar_link1_title'),
    '#size' => 60,
  );

  $form['uiowa_bar_link1']['uiowa_bar_link1_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => variable_get('uiowa_bar_link1_url'),
    '#size' => 60,
  );

  $form['uiowa_bar_link2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['uiowa_bar_link2']['uiowa_bar_link2_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('uiowa_bar_link2_title'),
    '#size' => 60,
  );

  $form['uiowa_bar_link2']['uiowa_bar_link2_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => variable_get('uiowa_bar_link2_url'),
    '#size' => 60,
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
  drupal_flush_all_caches();
  $service = _acquia_purge_service();
  if ($service->lockAcquire()) {
    $service->process();
    $service->lockRelease();
  }
  return system_settings_form($form);
}
