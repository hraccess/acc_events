<?php
/**
 * @file
 * acc_events.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function acc_events_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-access_constraint_type-field_access_constraint'
  $field_instances['taxonomy_term-access_constraint_type-field_access_constraint'] = array(
    'bundle' => 'access_constraint_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'entityreference_view_widget' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ical' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_access_constraint',
    'label' => 'Access Constraint',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Constraint');

  return $field_instances;
}
