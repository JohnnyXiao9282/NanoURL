# NanoURL

URL shortener with a C++ backend and a React + TypeScript frontend.

## Project Structure

- `backend/` — C++ code for the backend logic (URL shortening, expansion, etc.)
- `frontend/` — React + TypeScript frontend for user interaction

## Getting Started

### Backend (C++)
- Edit and build your C++ code in the `backend/` folder.
- Example entry point: `main.cpp`

### Frontend (React + TypeScript)
1. Go to the `frontend` directory:
   ```bash
   cd frontend
   ```
2. Install dependencies:
   ```bash
   npm install
   ```
3. Start the development server:
   ```bash
   npm run dev
   ```
4. Open your browser to the local address shown in the terminal (usually `http://localhost:5173`).

## Features
- Enter a long URL and get a shortened version.
- Copy the shortened URL with one click.
- Simple, modern UI with a dark header.

## To Do
- Connect frontend to backend API for real URL shortening.
- Add persistent storage to backend (optional).
- Deploy to production (optional).

---

MIT License
