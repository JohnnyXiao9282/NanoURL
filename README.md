# NanoURL

URL shortener with a C++ backend and a React + TypeScript frontend.

## Project Structure

- `backend/` — C++ code for the backend logic (URL shortening, expansion, etc.)
- `frontend/` — React + TypeScript frontend for user interaction

## Getting Started

### 1. Install dependencies (root and frontend)
```bash
npm install
cd frontend && npm install
```

### 2. Download C++ dependencies
- Download `httplib.h` from https://github.com/yhirose/cpp-httplib/blob/master/httplib.h and place it in `backend/src/`
- Download `json.hpp` from https://github.com/nlohmann/json/releases and place it in `backend/src/nlohmann/`

### 3. Run both frontend and backend together
From the project root:
```bash
npm run dev
```
This will start both the C++ backend server and the React frontend concurrently.

- The backend runs on [http://localhost:8080](http://localhost:8080)
- The frontend runs on [http://localhost:5173](http://localhost:5173)

## Features
- Enter a long URL and get a shortened version.
- Copy the shortened URL with one click (shows "Copied!" feedback).
- Simple, modern UI with a dark header.
- CORS enabled for local development.

## Notes
- The backend uses C++11 and requires `httplib.h` and `json.hpp` as described above.
- The frontend uses React, TypeScript, Vite, and Axios.
- All development can be run with a single command: `npm run dev`.

---

MIT License
