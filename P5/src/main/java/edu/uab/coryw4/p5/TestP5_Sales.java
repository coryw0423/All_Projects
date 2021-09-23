/*
 * File: TestP5_Sales.java
 * Author: Cory Wilson coryw4@uab.edu
 * Assignment:  P5 - EE333 Spring 2020
 * Vers: 1.0.1 08/15/2020 caw - initial coding
 */
package edu.uab.coryw4.p5;

import java.util.ArrayList;

/**
 * Test for Sales System
 *
 * @author coryw4
 */
public class TestP5_Sales {

    public static void main(String[] args) {
        println("TestSalesSystem");

        //Creating bank accounts
        EBank ebank = EBank.getInstance();

        EBankRecord bankAccount1 = new EBankRecord(new EBankAccount("First Student", 100.0), "stu1", 1);
        ebank.addBankRecord(bankAccount1);
        println("New EBank account " + bankAccount1.getBlazerID() + " created with balance "
                + bankAccount1.getEBankAccount().getBalance());
        EBankRecord bankAccount2 = new EBankRecord(new EBankAccount("Second Student", 80.0), "stu2", 1);
        ebank.addBankRecord(bankAccount2);
        println("New EBank account " + bankAccount2.getBlazerID() + " created with balance "
                + bankAccount2.getEBankAccount().getBalance());
        EBankRecord bankAccount3 = new EBankRecord(new EBankAccount("Third Faculty/Employee", 150.0), "fac1", 4);
        ebank.addBankRecord(bankAccount3);
        println("New EBank account " + bankAccount3.getBlazerID() + " created with balance "
                + bankAccount3.getEBankAccount().getBalance());

        // Make a ECardDB to use
        ECardDB db = ECardDB.getInstance();

        ECard ec1 = db.issueCard("First Student", "stu1", 1);
        ECard ec2 = db.issueCard("Second Student", "stu2", 1);
        ECard ec3 = db.issueCard("Third Faculty/Employee", "fac1", 4);

        

        //Creating products
        ArrayList<ProductIdentity> products = new ArrayList<>();
        ProductIdentity prod1 = new ProductIdentity(101, "Product1", 17.5);
        products.add(prod1);
        ProductIdentity prod2 = new ProductIdentity(102, "Product2", 10.7);
        products.add(prod2);
        ProductIdentity prod3 = new ProductIdentity(103, "Product3", 14.0);
        products.add(prod3);

        ECardLogger logger = new PrintLogger();

        //Creating a sale system instance
        SalesSystem salesSystem = new SalesSystem(products);
        salesSystem.initialize("sale123loc");
        salesSystem.add(logger);

        ebank.deposit(bankAccount2.getBlazerID(), 1000.0);
        EBankAccount account = bankAccount2.getEBankAccount();
        println("Balance before purchase is " + account.getBalance());
        if (salesSystem.validate(ec2)) {
            salesSystem.purchase(prod2);
        }
        println("Balance after purchase is " + account.getBalance());
    }

    // convenience println
    private static void println(String s) {
        System.out.println(s);
    }

    // print s after noting whether or not test passed
    // b will be true if test passed
    private static void printTestResult(boolean b, String s) {
        if (b) {
            println("Test passed: " + s);
        } else {
            println("Test failed: " + s);
        }
    }
}
