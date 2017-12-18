<?php

namespace Drupal\uiowa_bar\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements an example form.
 */
class SearchForm extends FormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'uiowa_bar_search_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
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
    $form['#attributes']['aria-label'] = 'site search';
    $form['#attributes']['role'] = 'search';
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $search_query = urlencode($form_state->getValue('search-terms'));
    $form_state->setRedirect('uiowa_bar.search_results', [
      'search' => $search_query,
    ]);
  }

}