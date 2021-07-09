package com.yasa.prak_db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
public class Program_1 {
 String url, usr, pwd, db;

 public Jdbc_1(){
	 db = "javadb";
	 url = "jdbc:mysql://localhost/" + db;
	 usr = "root";
	 pwd = "";
 }
 public Connection getConnection() {
	 Connection con = null;
	 try {
		 Class.forName("com.mysql.jdbc.Driver");
		 con = DriverManager.getConnection(url, usr, pwd);
		 System.out.println("Ok : Driver Ditemukan");
	 }
	 catch (ClassNotFoundException e) {
		 System.out.println("Error: Driver Tidak Ditemukan \n"+e+"\n");
	 }
	 catch (SQLException e) {
		 System.out.println("Error:Tidak Bisa Koneksi Ke Database\n"+
		 e+"\n");
 }
 return con;
 }
 private void PembuatDialog(){
	 System.out.println("Created By :
			 DnD ~ http://sidiq.mercubuana-yogya.ac.id");
			 System.exit(0);
			 }
			 public static void main(String[] args){
				 Program_1 dnd = new Program_1();
				 dnd.getConnection();
				 dnd.PembuatDialog();
			 }

 }
