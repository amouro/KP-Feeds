KP-Feeds
========

Create Drupal Features module: KP Article and Categrory Aggregator

Features module includes drupal settings incuding content type, taxonomy, importers, and attribute necessary modules.

In this Features module, two major importer are included for import data from http://unlimited.kptaipei.tw/ as drupal nodes

* KP Article source creator:
  bundled with content type "KP Category source", and create "KP Article source"
* KP Article Importer:
  bundled with content type "KP Article source", map all article data and create KP Articles
  
========
Install

1. Clone the repository, which contains all dependent modules. Optional: Download only kp_article_and_category_aggregator to your drupal site
2. Enable "KP Article and Categrory Aggregator" in Admin > Modules
3. Add content "KP Category source" and input the category api with your API KEY
4. After save it, click "Import". It will create "KP Article sources"
5. Find the new Article sources and import them.
