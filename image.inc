<?php

class ImageMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_photo_beskrivelse', 'field_text');
    // $this->addFieldMapping(array('field_fotoalbum'), array(963, TRUE));

    $this->addFieldMapping('field_bilde_tagg', '5')
         ->sourceMigration('ImageTags');
  }
}
