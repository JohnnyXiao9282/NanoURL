import axios from "axios";
import React, { useState } from "react";

const Converter: React.FC = () => {
  const [url, setUrl] = useState("");
  const [shortUrl, setShortUrl] = useState("");
  const [error, setError] = useState("");
  const [copied, setCopied] = useState(false);

  const handleShorten = async () => {
    if (!url.trim()) {
      setError("Please enter a URL.");
      setShortUrl("");
      return;
    }
    setError("");
    try {
      const response = await axios.post("http://localhost:8080/api/shorten", {
        url,
      });
      setShortUrl(response.data.shortUrl);
      setCopied(false);
    } catch {
      setError("Failed to shorten URL.");
      setShortUrl("");
      setCopied(false);
    }
  };

  const handleCopy = () => {
    if (shortUrl) {
      navigator.clipboard.writeText(shortUrl);
      setCopied(true);
      setTimeout(() => setCopied(false), 1200);
    }
  };

  return (
    <div
      style={{
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        alignItems: "center",
        minHeight: "100vh",
      }}
    >
      <textarea
        value={url}
        onChange={(e) => setUrl(e.target.value)}
        placeholder="Type your url"
        style={{ width: "600px", height: "20px", marginBottom: "12px" }}
      />
      <button
        type="button"
        onClick={handleShorten}
        style={{
          width: "70px",
          height: "30px",
          fontSize: "14px",
          paddingTop: "6px",
          paddingLeft: "13px",
        }}
      >
        Shorten
      </button>
      {error && <div style={{ color: "red", marginTop: 8 }}>{error}</div>}
      {shortUrl && (
        <div style={{ marginTop: 16 }}>
          Shortened URL:{" "}
          <a href={shortUrl} target="_blank" rel="noopener noreferrer">
            {shortUrl}
          </a>
          <button
            type="button"
            style={{
              marginLeft: 12,
              padding: "6px 14px",
              fontSize: "1rem",
              background: "#222",
              color: "#fff",
              border: "none",
              borderRadius: 4,
              cursor: "pointer",
            }}
            onClick={handleCopy}
          >
            {copied ? "Copied!" : "Copy"}
          </button>
        </div>
      )}
    </div>
  );
};

export default Converter;
