<?php
/**
 * @file
 * acc_events.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function acc_events_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'acc_access_events_feed';
  $feeds_importer->config = array(
    'name' => 'CSV Access Events',
    'description' => 'Import Access Events from CVS file for Access Humanitarian project',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'access_constraint_type',
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'UUID',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'access_constraint_type',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['acc_access_events_feed'] = $feeds_importer;

  return $export;
}
