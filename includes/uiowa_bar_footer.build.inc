<?php

/**
 * @file
 *
 * Build and theme the University of Iowa branding bar
 */

/**
 * Build out the University of Iowa branding bar.
 */
function build_uiowa_bar_footer() {
  $uiowa_bar = array();
  $uiowa_bar['ui-global-footer'] = array(
    '#attributes' => array('id' => array('ui-global-footer')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container'] = array(
    '#attributes' => array('class' => array('container')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container']['ui-logo'] = array(
    '#attributes' => array('id' => array('ui-footer-logo')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container']['ui-logo']['link'] = array(
    '#type' => 'link',
    '#title' => t('The University of Iowa'),
    '#href' => 'http://www.uiowa.edu',
  );
  $uiowa_bar['ui-global-footer']['container']['ui-global-footer-nav'] = array(
    '#attributes' => array('id' => array('ui-global-footer-nav')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container']['ui-global-footer-nav']['ui-global-links'] = array(
    '#attributes' => array('id' => array('ui-global-links')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container']['ui-global-footer-nav']['ui-global-links']['links'] = array(
    '#theme' => 'uiowa_bar_link_list',
    '#children' => array(
      0 => array(
        'label' => t('Phonebook'),
        'url' => 'http://www.uiowa.edu/homepage/directories/',
        'class' => 'phonebook',
        'title' => 'University of Iowa Phonebook'
      ),
      1 => array(
        'label' => t('Maps'),
        'url' => 'http://www.uiowa.edu/homepage/hub/tours.html',
        'class' => 'maps',
        'title' => 'University of Iowa Maps'
      ),
      2 => array(
        'label' => t('A-Z Index'),
        'url' => 'http://www.uiowa.edu/homepage/search/index.html',
        'class' => 'a-z',
        'title' => 'University of Iowa A-Z Index'
      ),
      3 => array(
        'label' => t('Search'),
        'url' => '#',
        'class' => 'search',
        'title' => 'University of Iowa Search'
      )
    )
  );

  return $uiowa_bar;
}

/**
 * Theme function to build a list of action links for the University of Iowa
 * branding bar.
 */
function theme_uiowa_bar_link_list($variables = array()) {
  $type = variable_get('uiowa_bar_link_style');
  $links = array();
  foreach ($variables['links']['#children'] as $link) {
    $link_content = array(
      '#prefix' => '<strong>',
      '#type' => 'markup',
      '#markup' => $link['label'],
      '#suffix' => '</strong>',
    );
    $link_url = $link['url'];
    $links[] = l(render($link_content), $link_url, array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array($type, $link['class']),
        'title' => $link['title'])
      )
    );
  }
  return theme('item_list', array('items' => $links));
}
