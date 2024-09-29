# DenloydMarBalane

## Description
Welcome to my portfolio! This is where I showcase the projects and skills I’ve developed as a 3rd-year 
Bachelor of Science in Information Systems (BSIS) student. This portfolio highlights some of the work I've done so far.

## How to Clone this Repository

1. On GitHub, navigate to the main page of the repository.
2. Above the list of files, click **Code**.
3. Copy the URL for the repository:
   - To clone the repository using HTTPS, under "HTTPS", click the clipboard icon.
   - To clone the repository using an SSH key (including a certificate issued by your organization's SSH certificate authority), click **SSH**, then click the clipboard icon.
   - To clone the repository using GitHub CLI, click **GitHub CLI**, then click the clipboard icon.
4. Open **Git Bash**.
5. Change the current working directory to the location where you want the cloned directory.
6. Type `git clone`, and then paste the URL you copied earlier. (git clone https://github.com/denloyd/Balane_Portfolio.git)
7. Press Enter to create your local clone. 

## How to Run the Website Using VSCode Live Server

### Step 1: Install the Live Server Extension
1. Open **Visual Studio Code (VSCode)**.
2. Click the **Extensions** icon (or press `Ctrl+Shift+X`).
3. Search for **Live Server**.
4. Find the "Live Server" extension by **Ritwick Dey** and click **Install**.

### Step 2: Open Your Project
1. Go to **File** > **Open Folder**.
2. Select the folder where your HTML files are.

### Step 3: Run Live Server
1. Open the HTML file you want to preview.
2. Right-click the file and choose **Open with Live Server**.
   - Or just click **Go Live** at the bottom of VSCode.

### Step 4: Check Your Website
- Your website should now open automatically in a browser.
- Any changes you make in VSCode will show up right away in the browser.


## HTML Tags and Elements Used

### Document Structure
- `<!DOCTYPE html>`: Defines the document type and version of HTML used, ensuring the browser renders the page in standards mode (HTML5).
- `<html lang="en">`: The opening tag for the HTML document. The `lang="en"` attribute specifies the language of the content (English).

### Body and Background
- `<body background="image/pics/bg.jpg">`: Defines the main content of the HTML document. Due to the prohibition of CSS, I used old attributes to set an image as the background, giving my portfolio a distinct look.

### Meta Tags
- `<meta charset="UTF-8">`: Specifies the character encoding for the HTML document (UTF-8), ensuring proper display of special characters.
- `<meta name="viewport" content="width=device-width, initial-scale=1.0">`: Makes the webpage responsive by controlling the layout on mobile browsers.

### Title and Font
- `<title>`: Defines the title of the webpage, which is displayed in the browser tab.
- `<font face="Arial">`: Specifies the font to be used for this website (an older HTML tag).
- `<b>`: I used this elements to bold my name 
- `<mark>`: To highlight the projects name 

### Header and Navigation
- `<header>`: Contains introductory content for the webpage, including logos and navigation links.
- `<nav>`: Defines a set of navigation links for menus.
- `&nbsp;`: It is a non breaking space, a entities that will not break into a new line.

### Tables
- `<table>`: Creates a table to organize content, with attributes like width, border, cellpadding, and cellspacing adjusting the layout.
- `<tr>`, `<td>`, `<th>`: Define the structure of rows and columns within the table.

### Images and Links
- `<img>`: Imports an image on the website. It includes the `src` attribute for the image source, `alt` for alternate text, and width/height for image size.
- `<a href="URL">`: Creates a hyperlink. The `href` attribute defines the destination URL, while the text between the tags is the clickable link.

### Content Structure
- `<hr>`: Creates a horizontal rule or line.
- `<h1>`: Defines the highest level of heading, used for titles or section headers.
- `<br>`: Produces a line break in the text.
- `<p align="center">`: Defines a paragraph of text, with the `align="center"` attribute centering the text and  `align="justify"` attribute justifying the text(also an older HTML tag)
- `<section>`: Defines thematic sections of content, such as “Projects,” “Skills,” “Contact,” and “Footer” to help organize the page.

### Forms and Inputs
- `<form>`: Represents a form that users can fill out and submit.
- `<input type="text">`: Creates a text input field.
- `<input type="email">`: Creates an input field for email addresses.
- `<textarea>`: Creates a multiline text input field.
- `<input type="submit">`: Creates a button to submit the form data.

### Footer and Centering
- `<footer>`: Defines the footer of the page, typically containing copyright information or additional links.
- `target="_blank"`: Opens the linked page in a new browser tab when clicked.

## Note
Due to the prohibition of CSS, I used old tags and attributes to arrange the text on the website properly.
