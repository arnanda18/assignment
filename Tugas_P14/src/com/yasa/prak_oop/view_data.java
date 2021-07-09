package com.yasa.prak_oop;

import java.awt.*;
import javax.swing.*;
import java.sql.*;
import javax.swing.table.*;
import java.awt.event.*;

public class view_data extends JPanel {
	
	String[] header = {"NIM","Nama"};
	JTable table_mhs = new JTable();
	JScrollPane scrollTable = new JScrollPane();
	public Object[][] isiTable = null;
	
	//Menu Bar
	private static final long serialVersionUID = 1L;
	
	JMenuBar mainMenu = new JMenuBar();
	JMenu File = new JMenu("File");
	JMenuItem exit = new JMenuItem("Exit");
	
	
	view_data(){
		
		Program_1 open = new Program_1 ();
		Connection mysql = open.getConnection();
		try {
		 Statement stmt = mysql.createStatement();
		 String sql = "SELECT * FROM siswa_191110227";
		 ResultSet res = stmt.executeQuery(sql);
		 ResultSetMetaData meta = res.getMetaData();
		 int kolom = meta.getColumnCount();
		 int baris = 0;
		 while(res.next()) {
			 baris = res.getRow();
		 }
		 
		 isiTable = new Object[baris][kolom];
		 int x = 0;
		 res.beforeFirst();
		 while(res.next()) {
			 isiTable[x][0] = res.getString("NIM");
			 isiTable[x][1] = res.getString("Nama");
			 x++;
		 }
		 scrollTable.setViewportView(table_mhs);
		 table_mhs.setModel(new DefaultTableModel(isiTable,header));
		 add(scrollTable, BorderLayout.NORTH);
		 stmt.close();
		 res.close();
		}
		catch (Exception ex){
			JOptionPane.showMessageDialog(null, ex);
		}
	}
	void Layout() {
		 JFrame frame = new JFrame("Data Mahasiswa");
		 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 view_data content = new view_data();
		 content.setOpaque(true);
		 frame.setSize(400, 200);
		 frame.setContentPane(content);
		 frame.pack();
		 frame.setLocationRelativeTo(null);
		 
		 
		 
		 
		 //Menu Bar
		 frame.setJMenuBar(mainMenu);
		 mainMenu.add(File);
		 File.add(exit);
		 
		 frame.setVisible(true);
		 	 
		 
	}
	
	void Action() {

		
		exit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		
		
	}
}
