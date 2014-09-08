<?php
/**
 * @file
 * kp_article_and_categrory_aggregator.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function kp_article_and_categrory_aggregator_filter_default_formats() {
  $formats = array();

  // Exported format: Full html.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full html',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
