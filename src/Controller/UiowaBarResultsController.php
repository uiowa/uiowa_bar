<?php

namespace Drupal\uiowa_bar\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Datetime\DateFormatterInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\Component\Utility\UrlHelper;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Returns responses for Uiowa Bar routes.
 */
class UiowaBarResultsController extends ControllerBase {

  /**
   * Constructs the controller object.
   */
  public function __construct() {}

  /**
   * Builds the response.
   */
  public function build() {
    $config = \Drupal::config('uiowa_bar.settings')->get('uiowa_bar');
    $search_terms = \Drupal::request()->get('search');
    $search_params = [
      'q' => $search_terms,
      'client' => 'our_frontend',
      'btnG' => 'Search',
      'output' => 'xml_no_dtd',
      'proxystylesheet' => 'our_frontend',
      'sort' => 'date',
      'entqr' => '0',
      'oe' => 'UTF-8',
      'ie' => 'UTF-8',
      'ud' => '1',
      'site' => 'default_collection',
    ];
    $params = UrlHelper::buildQuery($search_params);
    $build['search'] = [
      '#type' => 'link',
      '#title' => t('Search all University of Iowa for @terms', ['@terms' => $search_terms]),
      '#url' => Url::fromUri('https://search.uiowa.edu/search', ['query' => $search_params]),
      '#attributes' => [
        'target' => '_blank',
      ],
    ];
    $build['results_container'] = [
      '#type' => 'container',
      '#attributes' => [
        'id' => 'search-results',
      ],
    ];
    // Pass config to drupalSettings.
    $build['#attached']['drupalSettings']['uiowaBar']['engineId'] = $config['cse_engine_id'];
    $build['#attached']['drupalSettings']['uiowaBar']['cseScope'] = $config['cse_scope'];
    $build['#cache']['max-age'] = 0;

    return $build;
  }

}
