<?php
/**
 * @file
 * kp_article_and_categrory_aggregator.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function kp_article_and_categrory_aggregator_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'kp_article_importer';
  $feeds_importer->config = array(
    'name' => 'KP Article Importer',
    'description' => 'Import Articles to Conten Type: KP Articles',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'url_prefix_01' => '',
        'url_suffix_02' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'context' => array(
          'value' => '$.data.*',
        ),
        'sources' => array(
          'id' => array(
            'name' => 'id',
            'value' => 'id',
            'debug' => 0,
            'weight' => '1',
          ),
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '2',
          ),
          'post_date' => array(
            'name' => 'post date',
            'value' => 'post_date',
            'debug' => 0,
            'weight' => '3',
          ),
          'author' => array(
            'name' => 'author',
            'value' => 'author',
            'debug' => 0,
            'weight' => '4',
          ),
          'updated_date' => array(
            'name' => 'updated date',
            'value' => 'last_modify',
            'debug' => 0,
            'weight' => '5',
          ),
          'url' => array(
            'name' => 'url',
            'value' => 'url',
            'debug' => 0,
            'weight' => '6',
          ),
          'category' => array(
            'name' => 'category',
            'value' => 'category_name',
            'debug' => 0,
            'weight' => '7',
          ),
          'content' => array(
            'name' => 'content',
            'value' => 'content',
            'debug' => 0,
            'weight' => '8',
          ),
          'thumbnail' => array(
            'name' => 'thumbnail',
            'value' => 'thumbnail',
            'debug' => 0,
            'weight' => '9',
          ),
        ),
        'display_errors' => 0,
        'debug_mode' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'category',
            'target' => 'field_category_name',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          2 => array(
            'source' => 'post_date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'content',
            'target' => 'body',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'id',
            'target' => 'nid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'thumbnail',
            'target' => 'field_thumbnail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'kp_articles',
      ),
    ),
    'content_type' => 'article_importer',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['kp_article_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'kp_article_source_creator';
  $feeds_importer->config = array(
    'name' => 'KP Article source creator',
    'description' => 'Create Article source when Category Imported',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'url_prefix_01' => '',
        'url_suffix_02' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'debug' => 0,
            'weight' => '1',
          ),
          'id' => array(
            'name' => 'id',
            'value' => 'id',
            'debug' => 0,
            'weight' => '2',
          ),
        ),
        'context' => array(
          'value' => '$.data.*',
        ),
        'display_errors' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'debug_mode' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'feeds_source',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'article_importer',
      ),
    ),
    'content_type' => 'kp_category_source',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['kp_article_source_creator'] = $feeds_importer;

  return $export;
}
