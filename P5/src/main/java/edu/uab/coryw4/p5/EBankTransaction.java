/*
 * File: EBankTransaction.java
 * Author: Cory Wilson coryw4@uab.edu
 * Assignment:  P5 - EE333 Spring 2020
 * Vers: 1.0.1 08/15/2020 caw - initial coding
 */
package edu.uab.coryw4.p5;

/**
 * Transactions of the bank.
 *
 * @author coryw4
 */
public class EBankTransaction {

    private String source;
    private String destination;
    private String date;
    private double ebucks;
    private double dollars;

    public EBankTransaction(String source, String destination,
            String date, double ebucks, double dollars) {
        this.source = source;
        this.destination = destination;
        this.date = date;
        this.ebucks = ebucks;
        this.dollars = dollars;
    }

    public String getSource() {
        return source;
    }

    public String getDestination() {
        return destination;
    }

    public String getDate() {
        return date;
    }

    public double getEbucks() {
        return ebucks;
    }

    public double getDollars() {
        return dollars;
    }

    public void involves(String source, String destination) {
        this.source = source;
        this.destination = destination;
    }

    public void involves(String date, String source, String destination) {
        this.date = date;
        this.source = source;
        this.destination = destination;
    }
}
