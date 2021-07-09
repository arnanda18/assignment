package com.yasa.prak_oop;


import java.awt.event.*;
import javax.swing.*;
import java.sql.Connection;
import java.awt.*;
import java.sql.*;

//Author : Arnanda Nuryasa

public class Form_Input extends JFrame {
	
	 JLabel label_judul = new JLabel("FORM INPUT DATA");
	 JLabel label_NIM=new JLabel("NIM");
	 JTextField txt_NIM=new JTextField(30);
	 JLabel label_Nama=new JLabel("Name");
	 JTextField txt_Nama=new JTextField(50);
	 JButton buttonSearch=new JButton("Search by NIM");
	 JTextField txtSearch=new JTextField(50);
	 //JLabel info_search=new JLabel("masukkan nim");
	 JButton buttonSave=new JButton("Save");
	 JButton buttonUpdate=new JButton("Update");
	 JButton buttonDelete=new JButton("Delete");
	 JButton buttonExit = new JButton("Exit");
	 
	 JMenuBar mainMenu = new JMenuBar();
	 JMenu file = new JMenu("File");
	 JMenuItem viewData = new JMenuItem("View Data");
	 JMenu about = new JMenu("About");
	 JMenuItem profile = new JMenuItem("Profile");
	 
	 //Nim and Name
	 //JLabel label_inim=new JLabel("NIM	: 191110227");
	 //JLabel label_iname=new JLabel("Name	: Arnanda Nuryasa");
	 
	 Form_Input (){
		 setTitle("Input Data Mahasiswa");
		 setSize(500,350);
		 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	 }
	 
	 void Layout(){
		 getContentPane().setLayout(null);
		 
		 getContentPane().add(label_judul).setBounds(200,10,170,30);
		 getContentPane().add(label_NIM).setBounds(10,50,70,20);
		 getContentPane().add(txt_NIM).setBounds(80,50,200,20);
		 getContentPane().add(buttonSearch).setBounds(10,150,110,20);
		 getContentPane().add(txtSearch).setBounds(119,150,160,20);
		 //getContentPane().add(info_search).setBounds(305,70,100,20);		 
		 getContentPane().add(label_Nama).setBounds(10,90,70,20);
		 getContentPane().add(txt_Nama).setBounds(80,90,200,20);
		 getContentPane().add(buttonSave).setBounds(10,120,80,20);
		 getContentPane().add(buttonUpdate).setBounds(105,120,80,20);
		 getContentPane().add(buttonDelete).setBounds(200,120,80,20);
		 getContentPane().add(buttonExit).setBounds(10,180,80,20);
		 
		 setJMenuBar(mainMenu);
		 mainMenu.add(file);
		 file.add(viewData);
		 mainMenu.add(about);
		 about.add(profile);
		 
		 
		 //getContentPane().add(label_inim).setBounds(10,120,280,40);
		 //getContentPane().add(label_iname).setBounds(10,150,280,40);
		 setVisible(true);
		 
	 }
	 
	 void Action(){
	 //button Save
		 
		profile.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "<html> NIM : 191110227 <br> "
						+ " Nama : Arnanda Nuryasa</html>");
			}
		});
		
		viewData.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				view_data run = new view_data();
				run.Action();
				run.Layout();
			}
		});
		 
		buttonSave.addActionListener(new ActionListener(){
				 public void actionPerformed (ActionEvent e){
					Program_1 open = new Program_1();
					Connection mysql = open.getConnection();
					try {
					 Statement stmt = mysql.createStatement();
					 String sql = "INSERT INTO siswa_191110227 VALUES ('"+txt_NIM.getText()+"','"+txt_Nama.getText()+"');";
					 int i = stmt.executeUpdate (sql);
					 if (i == 1) {
						 JOptionPane.showMessageDialog(null,"Data Sudah Disimpan");
					 }
					}
					catch (Exception ex){
					 JOptionPane.showMessageDialog(null, ex.getMessage());
						}
					 }
		 });
	
		 // button search
		 buttonSearch.addActionListener(new ActionListener(){
			 public void actionPerformed (ActionEvent e){
				String search;
				Program_1 open = new Program_1 ();
				Connection mysql = open.getConnection();
				try {
					 search=txtSearch.getText();
					 Statement stmt = mysql.createStatement();
					 String sql = "SELECT * FROM siswa_191110227 "+ "WHERE NIM like '"+search+"'";
					 ResultSet res = stmt.executeQuery (sql);
					 if(res.next()){
						 txt_NIM.setText(res.getString(1));
						 txt_Nama.setText(res.getString(2));
					 }
					 else{
						 JOptionPane.showMessageDialog(null,"Data Sudah Ada");
				 }
				}
				catch (Exception ex){
					JOptionPane.showMessageDialog(null, ex.getMessage());
				}
			 }
		 });
		 // button update
		 buttonUpdate.addActionListener(new ActionListener() {
			public void actionPerformed (ActionEvent e) {
				Program_1 open = new Program_1 ();
				Connection mysql = open.getConnection();
				try {
					 Statement stmt = mysql.createStatement();
					 String sql = "UPDATE siswa_191110227 SET "+"Nama='"+txt_Nama.getText()+"'"+"WHERE "+"NIM='"+txt_NIM.getText()+"'";
					 int i = stmt.executeUpdate (sql);
					 if (i == 1) {
						 JOptionPane.showMessageDialog(null,"Data Sudah Diupdate");
					 }
				} 
				catch (Exception ex){
					JOptionPane.showMessageDialog(null, ex.getMessage());
				}
			 	}
		 });
		 // button delete
		 buttonDelete.addActionListener(new ActionListener() {
			public void actionPerformed (ActionEvent e) {
				Program_1 open = new Program_1 ();
				Connection mysql = open.getConnection();
				try {
					 Statement stmt = mysql.createStatement();
					 String sql = "DELETE FROM siswa_191110227 "+"WHERE NIM='"+txt_NIM.getText()+"'";
					 int i = stmt.executeUpdate (sql);
					 if (i == 1) {
						 JOptionPane.showMessageDialog(null,"Data Sudah Dihapus");
					 }
				}
				catch (Exception ex){
					JOptionPane.showMessageDialog(null, ex.getMessage());
				}
			}
		 });
		 buttonExit.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					System.exit(0);
				}
			});
		
	}
	public static void main(String[]args){
		Form_Input run = new Form_Input();
		run.Layout();
		run.Action();
	}
}