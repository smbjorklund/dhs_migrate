<?php

class ArticleMigration extends DHSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('body:format_mappings')
      ->defaultValue(1);

    // Note that we map migrated terms by the vocabulary ID.
    $this->addFieldMapping('field_tagg', '1')
         ->sourceMigration('Topics');
  }
}
