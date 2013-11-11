<?php

/**
 * @file
 *
 * Build and theme the University of Iowa branding bar footer
 */

/**
 * Build out the University of Iowa branding bar footer.
 */
function build_uiowa_bar_footer() {
  $uiowa_bar = array();
  $uiowa_bar['ui-global-footer'] = array(
    '#attributes' => array('id' => array('ui-global-footer')),
    '#type' => 'container',
  );
  $uiowa_bar['ui-global-footer']['container'] = array(
    '#attributes' => array('class' => array('container', 'l-container')),
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
        'label' => t('Phonebook/Email'),
        'url' => 'http://dnaapps.uiowa.edu/PublicDirectory/',
        'class' => 'phonebook',
        'title' => 'University of Iowa Phonebook and Email search',
      ),
      1 => array(
        'label' => t('A-Z Search'),
        'url' => 'http://www.uiowa.edu/homepage/search/index.html',
        'class' => 'a-z',
        'title' => 'University of Iowa A-Z Search',
      ),
      2 => array(
        'label' => t('About Iowa'),
        'url' => 'http://www.uiowa.edu/homepage/about-UI/index.html',
        'class' => 'about',
        'title' => 'About the University of Iowa',
      ),
      3 => array(
        'label' => t('Contact Us'),
        'url' => 'http://www.uiowa.edu/homepage/contact/index.html',
        'class' => 'contact',
        'title' => 'Contact the University of Iowa',
      ),
      4 => array(
        'label' => t('Calendars'),
        'url' => 'http://www.uiowa.edu/homepage/calendar/index.html',
        'class' => 'calendars',
        'title' => 'University of Iowa Calendars',
      ),
      5 => array(
        'label' => t('Maps'),
        'url' => 'http://www.uiowa.edu/homepage/hub/tours.html',
        'class' => 'maps',
        'title' => 'University of Iowa Maps',
      ),
    )
  );
  // Get year
  $year = date('Y');
  // Add copyright
  $uiowa_bar['ui-global-footer']['container']['copyright'] = array(
    '#attributes' => array('class' => array('ui-copyright')),
    '#type' => 'markup',
    '#prefix' => '<small>',
    '#suffix' => '</small>',
    '#markup' => '© ' . $year . ' The University of Iowa',
  );

  // Allow other modules to alter the footer render array.
  drupal_alter('uiowa_bar_footer', $uiowa_bar);

  return $uiowa_bar;
}

/**
 * Theme function to build a list of action links for the University of Iowa
 * branding bar.
 */
function theme_uiowa_bar_link_list($variables = array()) {
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
        'class' => array($link['class']),
        'title' => $link['title'])
      )
    );
  }
  return theme('item_list', array('items' => $links));
}
