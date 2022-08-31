<?php

/**
 * @file
 * HTML-related hook implementations.
 */

/**
 * Implements hook_preprocess().
 */
function aphisv1_preprocess(array &$variables) {
  if (!empty($variables['directory'])) {
    $variables['gesso_image_path'] = '/' . $variables['directory'] . '/dist/images';
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function aphisv1_preprocess_html(array &$variables) {
  $variables['include_back_to_top']
    = theme_get_setting('include_back_to_top', 'aphisv1') ?? TRUE;
  /** @var \Drupal\Core\Render\Renderer $renderer */
  $renderer = \Drupal::service('renderer');
  $themeConfig = \Drupal::config('aphisv1.settings');
  $renderer->addCacheableDependency($variables, $themeConfig);
}

/**
 * Implements hook_page_attachments_alter().
 */
function aphisv1_page_attachments_alter(array &$attachments) {
  $include_back_to_top = theme_get_setting('include_back_to_top') ?? TRUE;
  if ($include_back_to_top) {
    $attachments['#attached']['drupalSettings']['gesso']['backToTopThreshold']
      = theme_get_setting('threshold', 'aphisv1');
    $attachments['#attached']['drupalSettings']['gesso']['backToTopSmoothScroll']
      = theme_get_setting('smooth_scroll', 'aphisv1');
    /** @var \Drupal\Core\Render\Renderer $renderer */
    $renderer = \Drupal::service('renderer');
    $themeConfig = \Drupal::config('aphisv1.settings');
    $renderer->addCacheableDependency($attachments, $themeConfig);

  }
}