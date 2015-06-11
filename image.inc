<?php

class ImageMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_photo_beskrivelse', 'field_text');

    $this->addFieldMapping('field_album_foto', 'field_photo')
         ->sourceMigration('File');
    $this->addFieldMapping('field_album_foto:file_class')
         ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_album_foto:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_album_foto:title', 'field_photo:title')
         ->defaultValue(t('(c) De Heibergske Samlinger-Sogn Folkemuseum'));
    $this->addFieldMapping('field_album_foto:alt', 'field_photo:alt')
         ->defaultValue(t('(c) De Heibergske Samlinger-Sogn Folkemuseum'));

    $this->addFieldMapping('field_fotoalbum', 'field_fotoalbum')
         ->sourceMigration('Album');

    $this->addFieldMapping('field_bilde_tagg', '5')
         ->sourceMigration('ImageTags');
  }
}
