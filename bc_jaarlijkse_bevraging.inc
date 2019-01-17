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

    $this->surveyYear = 2018;
  }


  private function getContact($contactHash) {
    $sql = "
      select
        c.id
        , c.first_name
        , c.last_name
        , c.organization_name
        , c.employer_id
      from
        civicrm_contact c 
      where 
        c.id = %1
    ";
    $sqlParams = [
      1 => [$contactHash, 'Integer'],
    ];
    $dao = CRM_Core_DAO::executeQuery($sql, $sqlParams);

    if ($dao->fetch()) {
      $this->contactID = $dao->id;
      $this->contactFirstName = $dao->first_name;
      $this->contactLastName = $dao->last_name;
      $this->organizationID = $dao->employer_id;
      $this->organizationName = $dao->organization_name;
    }
    else {
      throw new Exception('Uw gegevens konden niet worden opgehaald.');
    }
  }
}
