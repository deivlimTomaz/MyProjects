import tkinter as tk
from tkinter import scrolledtext, messagebox
from datetime import datetime
import threading
import time
from turtle import width

class ChatBox:
    def __init__(self, root):
        self.root = root
        self.root.title("Python Chatbox")
        self.root.geometry("1280x720")
        self.root.configure(bg='#f0f0f0')

        # Create main frame
        main_frame = tk.Frame(root, bg='#f0f0f0')
        main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        # Title
        title_label = tk.Label(main_frame, text="Python Chatbox", font=('Arial', 16, 'bold'), bg='#f0f0f0', fg='#333')
        title_label.pack(pady=(0, 10))

        # Chat display area
        self.chat_display = scrolledtext.ScrolledText(main_frame, 
        wrap=tk.WORD, 
        width = 70, 
        height = 20, 
        font=('Arial', 10), 
        bg='white', 
        fg='black', 
        state=tk.DISABLED)

        self.chat_display.pack(fill=tk.BOTH, expand=True, pady=(0,10))

        # Input frame
        input_frame = tk.Frame(main_frame, bg='#f0f0f0')
        input_frame.pack(fill=tk.X, pady=(0, 10))

        # Message input
        self.message_entry = tk.Entry(
            input_frame,
            font=('Arial', 12),
            relief=tk.RAISED,
            borderwidth=2
        )

        self.message_entry.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(0, 5))
        self.message_entry.bind('<Return>', self.send_message)

        # Send button
        send_button = tk.Button(
            input_frame,
            text="Send",
            command = self.send_message,
            font = ('Arial', 10, 'bold'),
            bg = '#4CAF50',
            fg='white',
            relief=tk.RAISED,
            borderwidth = 2,
            cursor='hand2'
        )
        send_button.pack(side=tk.RIGHT)

        # Control buttons frame
        control_frame = tk.Frame(main_frame, bg='#f0f0f0')
        control_frame.pack(fill=tk.X)

        # Clear button
        clear_button = tk.Button(
            control_frame,
            text="Clear Chat",
            command = self.clear_chat,
            font=('Arial', 10),
            bg='#f44336',
            fg='white',
            relief=tk.RAISED,
            borderwidth=2,
            cursor='hand2'
        )
        clear_button.pack(side=tk.LEFT, padx=(0, 5))

        # Save button
        save_button = tk.Button(
            control_frame,
            text="Save Chat",
            command=self.save_chat,
            font=('Arial', 10),
            bg='#2196F3',
            fg='white',
            relief=tk.RAISED,
            borderwidth=2,
            cursor='hand2'
        )
        save_button.pack(side=tk.LEFT)

        # Status label
        self.status_label = tk.Label(
            control_frame,
            text="Ready to chat!",
            font=('Arial', 9),
            bg='#f0f0f0',
            fg='#666'
        )
        self.status_label.pack(side=tk.RIGHT)

        # Focus on input field
        self.message_entry.focus()

        # Welcome message
        self.add_system_message("Welcome to the Test Chatbox! Type your message and press Enter or click Send.")

    def add_message(self, sender, message, color='black'):
        """ Add a message to the chat display """
        self.chat_display.config(state=tk.NORMAL)

        # Add timestamp
        timestamp = datetime.now().strftime("%H:%M:%S")

        # Insert the message with formatting
        self.chat_display.insert(tk.END, f"[{timestamp}] {sender}: ", ('bold',))
        self.chat_display.insert(tk.END, f"{message}\n")

        # Configure text tags
        self.chat_display.tag_configure('bold', font=('Arial', 10, 'bold'))
        self.chat_display.tag_configure('system', foreground='#666', font=('Arial', 9, 'italic'))

        # Scroll to bottom
        self.chat_display.see(tk.END)
        self.chat_display.config(state=tk.DISABLED)

    def add_system_message(self, message):
        """ Add a system message """
        self.chat_display.config(state=tk.NORMAL)
        timestamp = datetime.now().strftime("%H:%M:%S")
        self.chat_display.insert(tk.END, f"[{timestamp}] System: {message}\n", ('system', ))
        self.chat_display.tag_configure('system', foreground='#666', font=('Arial', 9, 'italic'))
        self.chat_display.see(tk.END)
        self.chat_display.config(state=tk.DISABLED)

    def send_message(self, event=None):
        """ Send a message """
        message = self.message_entry.get().strip()
        if message:
            # Add user message
            self.add_message("You", message)
            self.message_entry.delete(0, tk.END)

            # Simulate a bot response (you can replace this with actual bot logic)
            self.simulate_bot_response(message)

            self.status_label.config(text=f"Message sent at {datetime.now().strftime('%H:%M:%S')}")

    def simulate_bot_response(self, user_message):
        """ Simulate a bot response (replace with actual bot logic) """
        def bot_reply():
            time.sleep(1)  # Simulate thinking time

            # Simple responses based on keywords
            message_lower = user_message.lower()
            if 'hello' in message_lower or 'hi' in message_lower:
                response = "Hello! How can I help you today?"
            elif 'how are you' in message_lower:
                response = "I'm doing well, thank you for asking! How are you?"
            elif 'goodbye' in message_lower or 'bye' in message_lower:
                response = "Goodbye! Have a great day!"
            elif 'time' in message_lower:
                response = f"The current time is {datetime.now().strftime('%H:%M:%S')}"
            elif 'help' in message_lower:
                response = "I'm a simple chatbot. Try saying hello, asking about the time, or just chat with me!"
            else:
                responses = [
                    "That's interesting! Tell me more.",
                    "I see. Can you elaborate on that?",
                    "Thanks for sharing that with me!",
                    "Hmm, that's worth thinking about.",
                    "I appreciate you telling me that!"
                ]
                import random
                response = random.choice(responses)
            
            self.add_message("Bot", response)

        # Run bot response in a separate thread to avoid blocking GUI
        threading.Thread(target=bot_reply, daemon=True).start()

    def clear_chat(self):
        """ Clear the chat display """
        result = messagebox.askyesno("Clear Chat", "Are you sure you want to clear the chat history?")
        if result:
            self.chat_display.config(state=tk.NORMAL)
            self.chat_display.delete(1.0, tk.END)
            self.chat_display.config(state=tk.DISABLED)
            self.add_system_message("Chat cleared.")
            self.status_label.config(text="Chat cleared")

    def save_chat(self):
        """ Save chat to a text file """
        try:
            from tkinter import filedialog
            filename = filedialog.asksaveasfilename(
                defaultextension=".txt",
                filetypes=[("Text files", "*.txt"), ("All files", "*.*")]
            )
            if filename:
                chat_content = self.chat_display.get(1.0, tk.END)
                with open(filename, 'w', encoding='utf-8') as file:
                    file.write(chat_content)
                self.status_label.config(text=f"Chat saved to {filename}")
                messagebox.showinfo("Success", f"Chat saved successfully to:\n{filename}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save chat:\n{str(e)}")


def main():
    # Create the main window
    root = tk.Tk()

    # Create the chatbox
    chatbox = ChatBox(root)

    #Start the GUI event loop
    root.mainloop()

if __name__ == "__main__":
    main()