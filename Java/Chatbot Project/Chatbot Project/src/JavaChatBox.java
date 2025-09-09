
// All libraries that we hava to use 

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;

public class JavaChatBox extends JFrame {
    private JTextArea chatDisplay;
    private JTextField messageInput;
    private JLabel statusLabel;
    private JScrollPane scrollPane;
}
