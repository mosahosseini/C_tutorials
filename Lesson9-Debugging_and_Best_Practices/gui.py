import tkinter as tk
import subprocess

# Function to run the Valgrind command in WSL and display the result
def run_valgrind():
    # Get the program name from the input field
    program_name = program_entry.get()
    
    if not program_name:
        result_label.config(text="Please enter a program name.")
        return

    if program_name.endswith(".c"):
        program_name[:-2]
    # Construct the Valgrind command
    #--log-file=valgrind_output.txt 
    valgrind_command = f"wsl valgrind --leak-check=full ./{program_name}"
    
    try:
        # Run the command in the WSL command window
        result = subprocess.check_output(valgrind_command, shell=True, stderr=subprocess.STDOUT, text=True)
        print(result)
        result_label.config(text=result)
    except subprocess.CalledProcessError as e:
        result_label.config(text=f"Error: {e.output}")

# Set up the Tkinter window
root = tk.Tk()
root.title("Valgrind Memory Leak Checker")

# Program name entry
program_entry_label = tk.Label(root, text="Enter Program Name:")
program_entry_label.pack()

program_entry = tk.Entry(root, width=30)
program_entry.pack()

# Run button
run_button = tk.Button(root, text="Run Valgrind", command=run_valgrind)
run_button.pack()

# Function to simulate button press and invoke it when Enter is pressed
def on_enter(event=None):
    # Change button appearance to simulate press
    run_button.config(relief=tk.SUNKEN)
    
    # Invoke the button (this runs the function associated with the button)
    run_button.invoke()
    
    # After a short delay, revert button appearance back to normal
    root.after(100, lambda: run_button.config(relief=tk.RAISED, bg="SystemButtonFace"))

# Bind the Enter key to trigger the button click
root.bind('<Return>', on_enter)

# Result display area
result_label = tk.Label(root, text="", justify=tk.LEFT, width=50, height=10, anchor="w")
result_label.pack()

# Start the GUI
root.mainloop()
