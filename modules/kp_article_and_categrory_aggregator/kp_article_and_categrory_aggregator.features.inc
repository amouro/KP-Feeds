<?php
/**
 * @file
 * kp_article_and_categrory_aggregator.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kp_article_and_categrory_aggregator_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function kp_article_and_categrory_aggregator_node_info() {
  $items = array(
    'article_importer' => array(
      'name' => t('KP Article source'),
      'base' => 'node_content',
      'description' => t('Save the url of the category you want to import.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Save the url of the category of articles you want to import.<br />
Format: http://api.kptaipei.tw/v1/category/[CATEGORY_ID]?accessToken=[YOUR_API_KEY]<br />
Get your API key at http://unlimited.kptaipei.tw/
<p>Category ID:
<ul>
<li>40:【柯P新政】</li>
<li>41:【真・柯文哲】</li>
<li>42:【新聞稿】</li>
</ul>
</p>'),
    ),
    'kp_articles' => array(
      'name' => t('KP Article'),
      'base' => 'node_content',
      'description' => t('儲存【柯P新政】、【真・柯文哲】、【新聞稿】三類文章資料'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'kp_category_source' => array(
      'name' => t('KP Category source'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Save the url of the category you want to import.<br />
Format: http://api.kptaipei.tw/v1/category/?accessToken=[YOUR_API_KEY]<br />
Get your API key at http://unlimited.kptaipei.tw/'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
