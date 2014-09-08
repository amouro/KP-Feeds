<?php
/**
 * @file
 * kp_article_and_categrory_aggregator.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function kp_article_and_categrory_aggregator_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'kp_article_source_creator-id-rewrite';
  $feeds_tamper->importer = 'kp_article_source_creator';
  $feeds_tamper->source = 'id';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://api.kptaipei.tw/v1/category/[id]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['kp_article_source_creator-id-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'kp_article_source_creator-name-rewrite';
  $feeds_tamper->importer = 'kp_article_source_creator';
  $feeds_tamper->source = 'name';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'Article source: [name]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['kp_article_source_creator-name-rewrite'] = $feeds_tamper;

  return $export;
}
