-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema atm
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema atm
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `atm` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci ;
USE `atm` ;

-- -----------------------------------------------------
-- Table `atm`.`Account_types`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Account_types` (
  `account_type` TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `account_name` VARCHAR(45) CHARACTER SET 'utf8mb3' NOT NULL,
  `intrest` DOUBLE NOT NULL,
  `atm_fee` DOUBLE NOT NULL,
  `withdraw_limit` SMALLINT NULL DEFAULT NULL,
  `description` TINYTEXT NOT NULL,
  PRIMARY KEY (`account_type`),
  UNIQUE INDEX `account_name_UNIQUE` (`account_name` ASC) VISIBLE)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Clients`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Clients` (
  `client_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  `last_name` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  `mobile_phone` VARCHAR(15) CHARACTER SET 'utf8mb3' NOT NULL,
  PRIMARY KEY (`client_id`),
  UNIQUE INDEX `mobile_phone_UNIQUE` (`mobile_phone` ASC) VISIBLE)
ENGINE = InnoDB
AUTO_INCREMENT = 9
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Currencies`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Currencies` (
  `digital_code` SMALLINT(3) UNSIGNED ZEROFILL NOT NULL,
  `letter_code` VARCHAR(10) CHARACTER SET 'utf8mb3' NOT NULL,
  `rate_to_UAH` DOUBLE NOT NULL,
  `name` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  PRIMARY KEY (`digital_code`),
  UNIQUE INDEX `currency_UNIQUE` (`digital_code` ASC) VISIBLE,
  UNIQUE INDEX `currency_name_UNIQUE` (`letter_code` ASC) VISIBLE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Banks`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Banks` (
  `bank_id` INT UNSIGNED NOT NULL,
  `name` VARCHAR(255) CHARACTER SET 'utf8mb3' NOT NULL,
  PRIMARY KEY (`bank_id`),
  UNIQUE INDEX `bank_id_UNIQUE` (`bank_id` ASC) VISIBLE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Offices`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Offices` (
  `office_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `bank_id` INT UNSIGNED NOT NULL,
  `is_head_office` TINYINT NOT NULL,
  `office_city` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  `office_street` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  `office_building` VARCHAR(30) CHARACTER SET 'utf8mb3' NOT NULL,
  PRIMARY KEY (`office_id`),
  UNIQUE INDEX `office_id_UNIQUE` (`office_id` ASC) VISIBLE,
  INDEX `bank_id_idx` (`bank_id` ASC) VISIBLE,
  CONSTRAINT `offices_bank_id`
    FOREIGN KEY (`bank_id`)
    REFERENCES `atm`.`Banks` (`bank_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Accounts`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Accounts` (
  `account_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `digital_code` SMALLINT UNSIGNED NOT NULL,
  `account_type` TINYINT UNSIGNED NOT NULL,
  `office_id` INT UNSIGNED NOT NULL,
  `client_id` INT UNSIGNED NOT NULL,
  `account_number` VARCHAR(30) CHARACTER SET 'utf8mb3' NOT NULL,
  `iban` VARCHAR(40) CHARACTER SET 'utf8mb3' NOT NULL,
  `is_blocked` TINYINT NOT NULL,
  `date_open` DATE NOT NULL,
  `balance` INT NOT NULL,
  `overdraft_limit` INT NOT NULL,
  `credit_sum_taken` INT NOT NULL,
  `loc_limit` INT NOT NULL,
  PRIMARY KEY (`account_id`),
  UNIQUE INDEX `iban_UNIQUE` (`iban` ASC) VISIBLE,
  UNIQUE INDEX `account_number_UNIQUE` (`account_number` ASC) VISIBLE,
  INDEX `currency_idx` (`digital_code` ASC) VISIBLE,
  INDEX `account_type_idx` (`account_type` ASC) VISIBLE,
  INDEX `client_id_idx` (`client_id` ASC) VISIBLE,
  INDEX `branch_id_idx` (`office_id` ASC) VISIBLE,
  CONSTRAINT `accounts_account_type`
    FOREIGN KEY (`account_type`)
    REFERENCES `atm`.`Account_types` (`account_type`),
  CONSTRAINT `accounts_client_id`
    FOREIGN KEY (`client_id`)
    REFERENCES `atm`.`Clients` (`client_id`),
  CONSTRAINT `accounts_digital_code`
    FOREIGN KEY (`digital_code`)
    REFERENCES `atm`.`Currencies` (`digital_code`),
  CONSTRAINT `accounts_office_id`
    FOREIGN KEY (`office_id`)
    REFERENCES `atm`.`Offices` (`office_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`AutoTellerMachine`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`AutoTellerMachine` (
  `machine_id` INT UNSIGNED NOT NULL,
  `office_id` INT UNSIGNED NOT NULL,
  `atm_street` VARCHAR(255) CHARACTER SET 'utf8mb3' NOT NULL,
  `atm_building` VARCHAR(100) CHARACTER SET 'utf8mb3' NOT NULL,
  PRIMARY KEY (`machine_id`),
  INDEX `branch_id_idx` (`office_id` ASC) VISIBLE,
  CONSTRAINT `atm_office_id`
    FOREIGN KEY (`office_id`)
    REFERENCES `atm`.`Offices` (`office_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Bank_ATM`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Bank_ATM` (
  `bank_id` INT UNSIGNED NOT NULL,
  `machine_id` INT UNSIGNED NOT NULL,
  `fee` DOUBLE NOT NULL,
  PRIMARY KEY (`bank_id`, `machine_id`),
  INDEX `machine_id_idx` (`machine_id` ASC) VISIBLE,
  CONSTRAINT `bank_atm_bank_id'`
    FOREIGN KEY (`bank_id`)
    REFERENCES `atm`.`Banks` (`bank_id`),
  CONSTRAINT `bank_atm_machine_id`
    FOREIGN KEY (`machine_id`)
    REFERENCES `atm`.`AutoTellerMachine` (`machine_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Cards`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Cards` (
  `card_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `account_id` INT UNSIGNED NOT NULL,
  `client_id` INT UNSIGNED NOT NULL,
  `pan` VARCHAR(20) CHARACTER SET 'utf8mb3' NOT NULL,
  `pin_code` INT NOT NULL,
  `expiration_date` DATE NOT NULL,
  `ccv` INT NOT NULL,
  PRIMARY KEY (`card_id`),
  UNIQUE INDEX `pan_UNIQUE` (`pan` ASC) VISIBLE,
  INDEX `iban_idx` (`account_id` ASC) VISIBLE,
  INDEX `cards_client_id_idx` (`client_id` ASC) VISIBLE,
  CONSTRAINT `cards_account_id`
    FOREIGN KEY (`account_id`)
    REFERENCES `atm`.`Accounts` (`account_id`),
  CONSTRAINT `cards_client_id`
    FOREIGN KEY (`client_id`)
    REFERENCES `atm`.`Clients` (`client_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `atm`.`Transactions`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`Transactions` (
  `trans_id` INT UNSIGNED NOT NULL,
  `machine_id` INT UNSIGNED NULL DEFAULT NULL,
  `account_from` INT UNSIGNED NOT NULL,
  `account_to` INT UNSIGNED NULL DEFAULT NULL,
  `sum` INT UNSIGNED NOT NULL,
  `date` DATE NOT NULL,
  `is_succesful` TINYTEXT NOT NULL,
  `desctiptiion` TINYTEXT NOT NULL,
  PRIMARY KEY (`trans_id`),
  INDEX `iban_idx` (`account_from` ASC) VISIBLE,
  INDEX `iban_idx1` (`account_to` ASC) VISIBLE,
  INDEX `trans_machine_id_idx` (`machine_id` ASC) VISIBLE,
  CONSTRAINT `trans_account_id_from`
    FOREIGN KEY (`account_from`)
    REFERENCES `atm`.`Accounts` (`account_id`),
  CONSTRAINT `trans_account_id_to`
    FOREIGN KEY (`account_to`)
    REFERENCES `atm`.`Accounts` (`account_id`),
  CONSTRAINT `trans_machine_id`
    FOREIGN KEY (`machine_id`)
    REFERENCES `atm`.`AutoTellerMachine` (`machine_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
