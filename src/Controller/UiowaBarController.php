<?php

namespace Drupal\uiowa_bar\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Datetime\DateFormatterInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Returns responses for Uiowa Bar routes.
 */
class UiowaBarController extends ControllerBase {

  /**
   * Constructs the controller object.
   */
  public function __construct() {}

  /**
   * Builds the response.
   */
  public function build() {

    $build['content'] = [
      '#type' => 'item',
      '#title' => $this->t('Content'),
      '#markup' => $this->t('Hello world!'),
    ];

    return $build;
  }

}
