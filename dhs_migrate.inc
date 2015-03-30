<?php

/**
 * @file dhs_migrate.inc
 * DHS import code.
 */

// /**
//  * Implements hook_migrate_api().
//  */
// function dhs_migrate_migrate_api() {
//   print "Loaded\n";
//   $api = array(
//     'api' => 2,
//     'groups' => array(
//       'content_migration' => array(
//         'title' => t('Drupal 6 to Drupal 7 migrations.'),
//       ),
//       'migrations' => array(),
//     ),
//   );

//   // Specify the DB connection and the source Drupal version.
//   $common_arguments = array(
//     'source_connection' => 'legacy',
//     'source_version' => 6,
//     'group_name' => 'content_migration',
//   );

//   // Register the user migration.
//   // We just use the migrate_d2d D6 migration class as-is.
//   $api['migrations']['User'] = $common_arguments + array(
//     'description' => t('Migration of users from Drupal 6'),
//     'class_name' => 'DrupalUser6Migration',
//   );

//   // For vocabulary migrations, source_vocabulary and destination_vocabulary are
//   // required arguments. Note that in Drupal 6 vocabularies did not have machine
//   // names, so we use the vocabulary ID to uniquely identify them.
//   $vocabulary_arguments = array(
//     'ImageTags' => array(
//       'description' => t('Migration of photo terms from Drupal 6'),
//       'source_vocabulary' => '5',  // D6 Vocabulary ID
//       'destination_vocabulary' => 'bilde',
//     ),
//     'Topics' => array(
//       'description' => t('Migration of Topics terms from Drupal 6'),
//       'source_vocabulary' => '1',  // D6 Vocabulary ID
//       'destination_vocabulary' => 'tags',
//     ),
//   );

//   // Node migrations - each has its own class derived from the migrate_d2d class,
//   // specifying its particular field mappings and transformations. source_type
//   // and destination_type are required arguments.
//   $node_arguments = array(
//     'Album' => array(
//       'class_name' => 'AlbumMigration',
//       'description' => t('Migration of photo album nodes from Drupal 6'),
//       'source_type' => 'fotoalbum',
//       'destination_type' => 'fotoalbum',
//     ),
//     'Image' => array(
//       'class_name' => 'ImageMigration',
//       'description' => t('Migration of bilde nodes from Drupal 6'),
//       'source_type' => 'bilde',
//       'destination_type' => 'bilde',
//       'dependencies' => array('ImageTags', 'Album'),
//     ),
//     'Article' => array(
//       'class_name' => 'ArticleMigration',
//       'description' => t('Migration of article nodes from Drupal 6'),
//       'source_type' => 'page',
//       'destination_type' => 'innhald',
//       'dependencies' => array('Topics'),
//     ),
//   );

//   // Tell the node migrations where the users are coming from, so they can
//   // set up the dependency and resolve D6->D7 uids.
//   $common_node_arguments = $common_arguments + array(
//       'user_migration' => 'User'
//     );

//   foreach ($node_arguments as $migration_name => $arguments) {
//     $arguments = array_merge_recursive($arguments, $common_node_arguments);
//     $api['migrations'][$migration_name] = $arguments;
//   }

//   print_r($api);
//   return $api;
// }

// /*
//  * Implements hook_flush_caches().
//  */
// function dhs_migrate_flush_caches() {
//   // Specify the DB connection and the source Drupal version.
//   $common_arguments = array(
//     'source_connection' => 'legacy',
//     'source_version' => 6,
//   );

//   // Register migrations.
//   _dhs_migrate_article($common_arguments);
//   _dhs_migrate_fotoalbum($common_arguments);
//   _dhs_migrate_bilde($common_arguments);
//   _dhs_migrate_article_tags($common_arguments);
//   _dhs_migrate_bilde_tags($common_arguments);
//   _dhs_migrate_users($common_arguments);
//   _dhs_migrate_files($common_arguments);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_article($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Migrate article nodes',
//     'machine_name' => 'ArticleMigration',
//     'source_type' => 'page', // Change this to your content type.
//     'destination_type' => 'innhold',
//     'user_migration' => 'UserMigration',
//     'dependencies' => array('ArticleTagMigration'),
//   );

//   Migration::registerMigration($migration_class = 'DrupalNode6Migration', $args['machine_name'], $args);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_fotoalbum($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Migrate fotoalbum nodes',
//     'machine_name' => 'FotoalbumMigration',
//     'source_type' => 'fotoalbum', // Change this to your content type.
//     'destination_type' => 'fotoalbum',
//     'user_migration' => 'UserMigration',
//     // 'dependencies' => array('ArticleTagMigration'),
//   );

//   Migration::registerMigration($migration_class = 'DrupalNode6Migration', $args['machine_name'], $args);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_bilde($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Migrate bilde nodes',
//     'machine_name' => 'BildeMigration',
//     'source_type' => 'bilde', // Change this to your content type.
//     'destination_type' => 'bilde',
//     'user_migration' => 'UserMigration',
//     'dependencies' => array('FotoalbumMigration'),
//   );

//   Migration::registerMigration($migration_class = 'DrupalNode6Migration', $args['machine_name'], $args);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_article_tags($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Migrate article tags',
//     'machine_name' => 'ArticleTagMigration',
//     'source_vocabulary' => $vid = 1, // The Vocab Id of the tags on the D6 instance.
//     'destination_vocabulary' => 'tags',
//   );

//   Migration::registerMigration($migration_class="DrupalTerm6Migration", $args['machine_name'], $args);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_bilde_tags($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Migrate bilde tags',
//     'machine_name' => 'BildeTagMigration',
//     'source_vocabulary' => $vid = 5, // The Vocab Id of the tags on the D6 instance.
//     'destination_vocabulary' => 'bilde',
//   );

//   Migration::registerMigration($migration_class = 'DrupalTerm6Migration', $args['machine_name'], $args);
// }

// /*
//  * @param $common_arguments
//  */
// function _dhs_migrate_users($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'User Migration',
//     'machine_name' => 'UserMigration',
//   );

//   Migration::registerMigration($migration_class="DrupalUser6Migration", $args['machine_name'], $args);
// }

// /**
//  * @param $common_arguments
//  */
// function _dhs_migrate_files($common_arguments) {
//   $args = $common_arguments + array(
//     'description' => 'Files migration.',
//     'machine_name' => 'FileMigration',
//     'source_dir' => '/home/ben/sites/devblog/sites/default/files/', // Absolute path to files folder.
//     'destination_dir' => 'public://images',
//   );

//   Migration::registerMigration($migration_class="DrupalFile6Migration", $args['machine_name'], $args);
// }
