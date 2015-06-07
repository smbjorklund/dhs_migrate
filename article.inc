<?php

class ArticleMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('body:format_mappings')
         ->defaultValue(1);

    $this->addFieldMapping('field_innhold_vedlegg', 'field_vedlegg')
         ->sourceMigration('File');
    $this->addFieldMapping('field_innhold_vedlegg:file_class')
         ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_innhold_vedlegg:preserve_files')
         ->defaultValue(TRUE);

    $this->addFieldMapping('field_innhold_foto', 'field_photo')
         ->sourceMigration('File');
    $this->addFieldMapping('field_innhold_foto:file_class')
         ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_innhold_foto:preserve_files')
        ->defaultValue(TRUE);

    // Keep the nid used in D6.
    $this->addFieldMapping('nid', 'nid');
    $this->addFieldMapping('is_new')
         ->defaultValue(TRUE);

    // Note that we map migrated terms by the vocabulary ID.
    $this->addFieldMapping('field_tagg', '1')
         ->sourceMigration('Topics');
  }
}
