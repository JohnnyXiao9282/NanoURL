import axios from "axios";
import React, { useEffect, useRef, useState, type KeyboardEvent } from "react";

type url = {
  url: string;
};

type shortUrl = {
  shortUrl: string;
};

const Coverter: React.FC = () => {
  const [url, setUrl] = useState("");
  const printUrl = (url: string) => {
    console.log(url);
  };
  return (
    <div style={{
        display: 'flex',
        flexDirection: 'column',
        justifyContent: 'center',
        alignItems: 'center',
        minHeight: '100vh'
    }}>
      <textarea
        value={url}
        onChange={(e) => setUrl(e.target.value)}
        placeholder="Type your url"
      />
      <button onClick={() => printUrl(url)}>Shorten</button>
    </div>
  );
};

export default Coverter;
