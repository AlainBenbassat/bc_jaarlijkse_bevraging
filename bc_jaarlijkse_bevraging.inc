<?php

class BcSurveyQuestion {
  public $question;
  public $answer;
  public $readOnly = FALSE;
}

class BcSurvey {
  public $contactID;
  public $contactFirstName;
  public $contactLastName;
  public $organizationID;
  public $organizationName;
  public $surveyYear;
  public $questions = [];

  public function __construct($contactHash) {
    $this->getContact($contactHash);
  }


  private function getContact($contactHash) {
    // get the user with this checksum
    $params = array(
      'hash' => $contactHash,
    );
    $contact = civicrm_api3('contact', 'get', $params);

    // make sure we have a contact
    if ($contact['count'] != 1) {
      throw new Exception('Uw gegevens konden niet opgehaald worden.');
    }
    $contact = reset($contact['values']);

    var_dump($contact);
  }
}
