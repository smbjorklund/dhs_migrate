<?php

class AlbumMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_album_beskrivelse', 'field_text');
    $this->addFieldMapping('field_album_beskrivelse:format', 'field_text:format')
         ->callbacks(array($this, 'mapFormat'));
  }
}
