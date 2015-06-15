<?php
/**
 * @file
 * Build the UIowa bar results page.
 */

/**
 * Build the results page markup.
 */
function uiowa_bar_build_results() {
  $query_string = (drupal_get_query_parameters() ? drupal_get_query_parameters() : NULL);
  $path = drupal_get_path('module', 'uiowa_bar');

  $search_params = array(
    'q' => $query_string['search'],
    'btnG' => 'Search',
    'client' => 'our_frontend',
    'output' => 'xml_no_dtd',
    'proxystylesheet' => 'our_frontend',
    'sort' => 'date',
    'entqr' => '0',
    'oe' => 'UTF-8',
    'ie' => 'UTF-8',
    'ud' => '1',
    'site' => 'default_collection',
  );

  $params = drupal_http_build_query($search_params);

  $results = array(
    'heading' => array(
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
      'link' => array(
        '#type' => 'link',
        '#title' => t('Search the University of Iowa for @terms', array('@terms' => $query_string['search'])),
        '#href' => "http://search.uiowa.edu/search?{$params}",
        '#attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'wrapper' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'search-results',
      ),
      '#attached' => array(
        'js' => array(
          array(
            'data' => array('uiowaBar' => array('cseScope' => variable_get('uiowa_bar_cse_scope'))),
            'type' => 'setting',
          ),
          array(
            'data' => array('uiowaBar' => array('engineId' => variable_get('uiowa_bar_cse_engine_id'))),
            'type' => 'setting',
          ),
          array(
            'data' => $path . '/js/cse.results.js',
            'type' => 'file',
          ),
        ),
      ),
    ),
  );

  return $results;
}
