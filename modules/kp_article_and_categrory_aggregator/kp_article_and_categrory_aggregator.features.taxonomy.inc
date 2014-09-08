<?php
/**
 * @file
 * kp_article_and_categrory_aggregator.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kp_article_and_categrory_aggregator_taxonomy_default_vocabularies() {
  return array(
    'article_category' => array(
      'name' => 'Article Category',
      'machine_name' => 'article_category',
      'description' => '文章類別',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
