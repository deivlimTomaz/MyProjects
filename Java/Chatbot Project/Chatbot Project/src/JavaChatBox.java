
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

    // Colors of chat
    
    private final Color BACKGROUND_COLOR = new Color(255, 255, 255);
    private final Color SEND_BUTTON_COLOR = new Color(0, 162, 0);
    private final Color CLEAR_BUTTON_COLOR = new Color(239, 11, 11);
    private final Color SAVE_BUTTON_COLOR = new Color(32, 11, 172);

    public JavaChatBox(){
        initializeComponents();
        
    }

    private void initializeComponents() {
        // Main window setup

        setTitle("SIGAA Chatbox");
        setSize(1280, 720);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        getContentPane().setBackground(BACKGROUND_COLOR);

        // Chat display area

        chatDisplay = new JTextArea();
        chatDisplay.setEditable(false);
        chatDisplay.setFont(new Font("Arial", Font.PLAIN, 12));
        chatDisplay.setBackground(Color.WHITE);
        chatDisplay.setMargin(new Insets(10, 10, 10, 10 ));

        // Scroll pane for chat display
        scrollPane = new JScrollPane(chatDisplay);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setBorder(BorderFactory.createLoweredBevelBorder());
        

    }
}
