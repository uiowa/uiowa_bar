<?php
/**
 * @file
 * Build and theme the University of Iowa branding bar.
 */

/**
 * Build out the University of Iowa branding bar.
 */
function build_uiowa_bar() {
  $varient = variable_get('uiowa_bar_varient');
  $theme = variable_get('uiowa_bar_color_palette');
  $base_path = $GLOBALS['base_path'];
  $uiowa_bar = array();

  $uiowa_bar['ui-global-bar'] = array(
    '#attributes' => array(
      'id' => 'ui-wrapper',
      'role' => 'region',
      'aria-label' => 'UI global header',
    ),
    '#type' => 'container',
  );

  $uiowa_bar['ui-global-bar']['container'] = array(
    '#attributes' => array('class' => array('container', 'l-container')),
    '#type' => 'container',
  );

  if ($varient == 'osl-varient') {
    $uiowa_bar['ui-global-bar']['container']['division-directory'] = array(
      '#attributes' => array('class' => array('division-directory')),
      '#type' => 'container',
    );

    $uiowa_bar['ui-global-bar']['container']['division-directory']['dosl-wrapper'] = array(
      '#attributes' => array('class' => array('dosl-wrapper')),
      '#type' => 'container',
    );
    $uiowa_bar['ui-global-bar']['container']['division-directory']['dosl-wrapper']['text'] = array(
      '#markup' => '<div id="osl-logo"><i class="ui-glyph-icon-osl-logo" aria-hidden="true"></i><span class="element-invisible">Division of Student Life</span></div><p class="adr">The Division of Student Life fosters student success by creating and promoting inclusive educationally purposeful services and activities within and beyond the classroom.</p>',
    );

    $uiowa_bar['ui-global-bar']['container']['division-directory']['division-menu'] = array(
      '#markup' => '<ul class="division-menu"><li class="has-subnav"><a href="#" class="directory-link">Directory Navigation</a><div class="division-show-hide"><ul class="menu-list"><li><a href="http://studentlife.uiowa.edu/">Division of Student Life</a></li><li><a href="http://csil.uiowa.edu/">Center for Student Involvement &amp; Leadership</a></li><li><a href="http://counseling.studentlife.uiowa.edu/">Counseling Service</a></li><li><a href="http://dos.uiowa.edu/">Dean of Students</a></li><li><a href="http://housing.uiowa.edu/">Housing & Dining</a></li></ul><ul class="menu-list"><li><a href="http://imu.uiowa.edu/">Iowa Memorial Union</a></li><li><a href="http://pickone.uiowa.edu">Pick One</a></li><li><a href="http://recserv.uiowa.edu/">Recreational Services</a></li><li><a href="http://rvap.org/">Rape Victim Advocacy Program</a></li><li><a href="http://osmrc.uiowa.edu/">Sexual Misconduct Response Coordinator</a></li></ul><ul class="menu-list"><li><a href="http://sds.studentlife.uiowa.edu">Student Disability Services</a></li><li><a href="http://studenthealth.uiowa.edu/">Student Health &amp; Wellness</a></li><li><a href="http://wrac.uiowa.edu/">Women&rsquo;s Resource &amp; Action Center</a></li><li><a href="http://studentlife.uiowa.edu/about/rocklin/">Vice President for Student Life</a></li></ul></div></li></ul>',
    );
  }

  $uiowa_bar['ui-global-bar']['container']['ui-logo'] = array(
    '#attributes' => array('id' => array('ui-logo')),
    '#type' => 'container',
  );

  $uiowa_bar['ui-global-bar']['container']['ui-logo']['link'] = array(
    '#markup' => '<a href="http://www.uiowa.edu" title="The University of Iowa"><i class="ui-glyph-icon-domewordsingle" aria-hidden="true"></i><span class="element-invisible">The University of Iowa</span></a>',
  );

  if ($varient == 'osl-varient') {
    $uiowa_bar['ui-global-bar']['container']['osl-wordmark'] = array(
      '#attributes' => array('id' => array('osl-wordmark')),
      '#type' => 'container',
    );

    $uiowa_bar['ui-global-bar']['container']['osl-wordmark']['link'] = array(
      '#markup' => '<a href="#" class="directory-toggle"><i class="ui-glyph-icon-osl-wordmark" aria-hidden="true"></i><span class="element-invisible">Division of Student Life</span></a>',
    );
  }

  if ($varient == 'engineering-varient') {
    if ($theme == 'uiowa-bar-dark' || $theme == 'uiowa-bar-large-dark') {
      $coe_wordmark = $base_path . drupal_get_path('module', 'uiowa_bar') . '/images/coe_wordmark_wht.png';
    }
    else {
      $coe_wordmark = $base_path . drupal_get_path('module', 'uiowa_bar') . '/images/coe_wordmark_blk.png';
    }
    $coe_wordmark = '<img src="' . $coe_wordmark . '" alt="College of Engineering" />';

    $uiowa_bar['ui-global-bar']['container']['engineering-wordmark'] = array(
      '#attributes' => array('id' => array('engineering-wordmark')),
      '#type' => 'container',
    );

    $uiowa_bar['ui-global-bar']['container']['engineering-wordmark']['link'] = array(
      '#markup' => l($coe_wordmark, '//www.engineering.uiowa.edu',
        array(
          'html' => TRUE,
          'attributes' => array(
            'class' => 'engineering-wordmark-link',
            'id' =>'engineering-wordmark-link',
          ),
        )
      ),
    );
  }

  $uiowa_bar['ui-global-bar']['container']['ui-search-toggle'] = array(
    '#markup' => '<a href="#" title="Open search bar" id="ui-search-toggle" class="is-active"><i class="ui-glyph-icon-ui-search" aria-hidden="true"></i><span class="element-invisible">Toggle Search</span></a>',
  );

  $uiowa_bar['ui-global-bar']['container']['ui-search'] = array(
    '#attributes' => array(
      'id' => array('ui-search'),
      'class' => array('is-visible'),
    ),
    '#type' => 'container',
  );

  $uiowa_bar['ui-global-bar']['container']['ui-search']['search-form'] = drupal_get_form('uiowa_bar_search_form');

  // Allow other modules to alter the top render array.
  drupal_alter('uiowa_bar_top', $uiowa_bar);

  return $uiowa_bar;
}

/**
 * Build out search form for the GSA.
 */
function uiowa_bar_search_form($form, &$form_state) {
  $form = array();
  $form['search-icon'] = array(
    '#markup' => '<i class="ui-glyph-icon-ui-search" aria-hidden="true"></i>',
  );
  $form['search-terms'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
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

  $form['#attributes']['aria-label'][] = 'site search';
  $form['#attributes']['role'] = 'search';
  return $form;
}

/**
 * Submit handler for full search form.
 */
function uiowa_bar_search_form_submit($form, &$form_state) {
  // Set the redirect.
  $search_query = urlencode($form_state['values']['search-terms']);
  $form_state['redirect'] = url($form['#action'] . '?search=' . $search_query, array('absolute' => FALSE));
}
