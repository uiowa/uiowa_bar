<?php

namespace Drupal\uiowa_bar\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

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
          'form-control-sm',
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
          'mx-0',
          'form-control-sm',
          'btn-sm',
          'btn-dark',
        ]
      ],
    ];
    $form['#action'] = $GLOBALS['base_url'] . '/google-search';
    // Use core search CSS in addition to this module's css.
    // (keep it general in case core search is enabled).
    $form['#attributes']['class'][] = 'uiowa-bar--navbar--search-form';
    $form['#attributes']['class'][] = 'form-row';
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
    $form_state->setRedirectUrl(Url::fromRoute('uiowa_bar.search_results', [], [
      'query' => [
        'search' => $form_state->getValue('search-terms'),
      ],
    ]));
  }

}
