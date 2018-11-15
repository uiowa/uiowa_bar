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
    $form = [];
    $form['search-terms'] = [
      '#type' => 'textfield',
      '#title' => t('Search'),
      '#label_attributes' => [
        'class' => [
          'sr-only',
        ],
      ],
      '#attributes' => [
        'placeholder' => 'Search this site',
        'class' => [
          'form-control',
          'mt-0',
        ]
      ],
      '#maxlength' => '256',
      '#size' => '15',
    ];
    $form['submit-search'] = [
      '#type' => 'submit',
      '#value' => t('Search'),
      '#name' => 'btnG',
      '#attributes' => [
        'class' => [
          'ml-1',
          'mr-0',
        ]
      ],
    ];
    $form['#action'] = $GLOBALS['base_url'] . '/google-search';
    // Use core search CSS in addition to this module's css.
    // (keep it general in case core search is enabled).
    $form['#attributes']['class'][] = 'uiowa-bar--navbar--search-form';
    $form['#attributes']['class'][] = 'form-inline';
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
