<?php

namespace Drupal\uiowa_bar\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure Uiowa Bar settings for this site.
 */
class SettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'uiowa_bar_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['uiowa_bar.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildForm($form, $form_state);
    $config = $this->config('uiowa_bar.settings');

    $form['markup'] = [
      '#type' => 'markup',
      '#markup' => t('<p>These settings allows you to customize the top University of Iowa branding bar.</p>'),
    ];
    $form['wordmark'] = [
      '#type' => 'radios',
      '#title' => t('Wordmark'),
      '#required' => TRUE,
      '#default_value' => $config->get('uiowa_bar.wordmark'),
      '#options' => [
        'uiowa' => t('University'),
        'uihc' => t('UI Healthcare')
      ],
      '#description' => t('Choose between the University or UI Healthcare wordmarks'),
    ];
    $form['link_1'] = [
      '#type' => 'details',
      '#title' => 'Link 1',
    ];
    $form['link_1']['link_1_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $config->get('uiowa_bar.link_1_title'),
      '#size' => 60,
    ];
    $form['link_1']['link_1_url'] = [
      '#type' => 'url',
      '#title' => t('URL'),
      '#default_value' => $config->get('uiowa_bar.link_1_url'),
      '#size' => 60,
    ];
    $form['link_2'] = [
      '#type' => 'details',
      '#title' => 'Link 2',
    ];
    $form['link_2']['link_2_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $config->get('uiowa_bar.link_2_title'),
      '#size' => 60,
    ];
    $form['link_2']['link_2_url'] = [
      '#type' => 'url',
      '#title' => t('URL'),
      '#default_value' => $config->get('uiowa_bar.link_2_url'),
      '#size' => 60,
    ];
    $form['cse_engine_id'] = [
      '#type' => 'textfield',
      '#title' => t('Search Engine ID'),
      '#default_value' => $config->get('uiowa_bar.cse_engine_id'),
      '#description' => t('Enter the CSE Engine ID. The default is 015014862498168032802:ben09oibdpm.'),
      '#size' => 60,
      '#required' => TRUE,
    ];
    $form['cse_scope'] = [
      '#type' => 'checkbox',
      '#title' => t('Limit Custom Search to this Site'),
      '#default_value' => $config->get('uiowa_bar.cse_scope'),
      '#description' => t('If checked, the Google Custom Search will be scoped to this site only. If you are using a CSE ID that includes multiple sites in it, you will likely want to uncheck this.'),
      '#size' => 60,
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    parent::validateForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $this->config('uiowa_bar.settings')
      ->set('uiowa_bar.wordmark', $form_state->getValue('wordmark'))
      ->set('uiowa_bar.link_1_title', $form_state->getValue('link_1_title'))
      ->set('uiowa_bar.link_1_url', $form_state->getValue('link_1_url'))
      ->set('uiowa_bar.link_2_title', $form_state->getValue('link_2_title'))
      ->set('uiowa_bar.link_2_url', $form_state->getValue('link_2_url'))
      ->set('uiowa_bar.cse_engine_id', $form_state->getValue('cse_engine_id'))
      ->set('uiowa_bar.cse_scope', $form_state->getValue('cse_scope'))
      ->save();
    parent::submitForm($form, $form_state);
  }

}
