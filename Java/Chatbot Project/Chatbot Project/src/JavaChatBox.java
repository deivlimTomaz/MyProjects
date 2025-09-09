
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
        setupLayout();
        
    }

    private void initializeComponents() {
        // Main window setup

        setTitle("SIGAA Chatbox");
        setSize(800, 600);
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

        // Message input field
        messageInput = new JTextField();
        messageInput.setFont(new Font("Arial", Font.PLAIN, 12));
        messageInput.setBorder(BorderFactory.createCompoundBorder(BorderFactory.createRaisedBevelBorder(), new EmptyBorder(5, 5, 5, 5)));

        // Status label
        statusLabel = new JLabel("Ready to chat!");
        statusLabel.setFont(new Font("Arial", Font.PLAIN, 9));
        statusLabel.setForeground(new Color(102, 102, 102));
    }

    private void setupLayout(){
        // Main content panel
        JPanel mainPanel = new JPanel(new BorderLayout(10, 10));
        mainPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel.setBackground(BACKGROUND_COLOR);

        // Title
        JLabel titleLabel = new JLabel("SIGAA Chatbox", JLabel.CENTER);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 16));
        titleLabel.setForeground(new Color(51, 51, 51));
        mainPanel.add(titleLabel, BorderLayout.NORTH);

        // Chat display
        mainPanel.add(scrollPane, BorderLayout.CENTER);

        // Bottom panel (input + buttons)
        JPanel bottomPanel = new JPanel(new BorderLayout(5, 5));
        bottomPanel.setBackground(BACKGROUND_COLOR);

        // Input panel
        JPanel inputPanel = new JPanel(new BorderLayout(5, 0));
        inputPanel.setBackground(BACKGROUND_COLOR);
        inputPanel.add(messageInput, BorderLayout.CENTER);

        // Send button
        JButton sendButton = createStyledButton("Send", SEND_BUTTON_COLOR);
        inputPanel.add(sendButton, BorderLayout.EAST);
        bottomPanel.add(inputPanel, BorderLayout.CENTER);

        // Control buttons panel
        JButton clearButton = createStyledButton("Clear chat", CLEAR_BUTTON_COLOR);
        JButton saveButton = createStyledButton("Save chat", SAVE_BUTTON_COLOR);

        controlPanel.add(clearButton);
        controlPanel.add(saveButton);
        controlPanel.add(Box.createHorizontalGlue());
        controlPanel.add(statusLabel);

        bottomPanel.add(controlPanel, BorderLayout.SOUTH);
        
        


    }

    public static void main(String[] args){
        // Set system look and feel

        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Create and show the chatbox
        SwingUtilities.invokeLater(() -> {
            new JavaChatBox().setVisible(true);
        });
    }
}
