<?php

class ArticleMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

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

    // Norwegian topic.
    $this->addFieldMapping('field_innhold_tagg', '1')
         ->sourceMigration('Topics');
    $this->addFieldMapping('field_innhold_tagg:source_type')
         ->defaultValue('tid');

    // English topic.
    $this->addFieldMapping('field_innhold_tagg_en', '4')
         ->sourceMigration('Category');
    $this->addFieldMapping('field_innhold_tagg_en:source_type')
         ->defaultValue('tid');

  }
}
