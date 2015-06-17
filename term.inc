<?php
/**
 * @file
 * Implementation of DrupalTermMigration for Drupal 6 sources.
 */

/**
 * Handling specific to a Drupal 6 source for taxonomy terms.
 */
class DHSTerm6Migration extends DrupalTerm6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->addFieldMapping('language', 'language')
         ->defaultValue('und');
  }

  /**
   * Implementation of DrupalTermMigration::query().
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = parent::query();
    $query->addField('td', 'language');
    return $query;
  }
}
